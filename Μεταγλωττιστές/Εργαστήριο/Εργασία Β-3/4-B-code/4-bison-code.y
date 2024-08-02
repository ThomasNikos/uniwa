/*	Όνομα αρχείου:	4-bison-code.y

	Περιγραφή:	Απλός συναντικός αναλυτής με τη χρήση Bison. 

	Συγγαφέας:	Ομάδα Α4 - Τμήματος Α3 Εργαστηρίου Μετταγλωτιστών

	Σχόλια:		Ο συντακτικός αναλυτής αναγνωρίζει: 
				Την δομή πηγαίου κώδικα, δηλώσεις μεταβλητών, πίνακες, ενσωματωμένες συναρτήσεις, δήλωση  
				συναρτήσεων χρήστη, απλών εκφράσεων, σύνθετες δηλώσεις, όπως και την εντολή return. 
				Ανιχνεύονται συντακτικά λάθη και εμφανίζονται στην οθόνη ένα μήνυμα επιτυχίας ή αποτυχίας 
				ανάλυσης του αρχείου εισόδου και παράγεται ένα αρχείου εξόδου με αναλυτικότερη περιγραφή.
				
	Οδηγίες εκτέλεσης:	Εισαγωγή της λέξης make στον τρέχον κατάλογο ή
						bison -d 4-bison-code.y
						flex 4-bison-code.l
						gcc 4-bison-code.tab.c lex.yy.c -o 4-bison-code  -lm
                    	./4-bison-code input.txt output.txt για εκτέλεση σε Linux
						ή 4-bison-code input.txt output.txt για εκτέλεση σε Windows.
*/

/* Ορισμοί και δηλώσεις γλώσσας C. */
%{

/* Δήλωση των αρχείων επικεφαλίδας και ορισμός τύπου δεδομένων. */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double

/* Δήλωση εξωτερικής συνάρτησης yylex του ΛΑ και των pointers για τα αρχεία εισόδου και εξόδου. */
extern int yylex(void);
extern FILE *yyin, *yyout;

/* Σωστές και λάθος λέξεις που υπολογίζονται από τον ΛΑ. */
extern int correct_words;
extern int wrong_words;

/* Δημιουργία μετρητών: */ 
int correct_expressions = 0;
int wrong_expressions = 0;
int par_warn = 0;

/* Δήλωση συνάρτησης yyerror. */
void yyerror (const char *msg);
%}

/* Δηλώσεις και ορισμοί Bison. */

/* Ορισμός των λεκτικών μονάδων. */
%token DELIMITER IDENTIFIER KEYWORD STRING INTEGER FLOAT PLUS MINUS TIMES DIVIDE POWER COMMENT NEG
%token UNKNOWN_TOKEN NEWLINE MINUS_ASSIGN PLUS_ASSIGN TIMES_ASSIGN MOD DIVIDE_ASSIGN AMPERSAND 
%token PRINT LEFT_PT RIGHT_PT SEMICOLON ASSIGNOP CMP_OPERATOR TYPE SCAN LEN CMP COMMA FUNC LEFT_BR  
%token IF WHILE FOR RETURN DOUBLE_PLUS DOUBLE_MINUS LOGIC_OPERATOR LOG_NOT RIGHT_AR LEFT_AR RIGHT_BR

/* Ορισμός Προτεραιοτήτων. */ 
%left PLUS MINUS
%left TIMES DIVIDE
%left NEG
%right POWER
%left LEFT_PT RIGHT_PT

/* Ορισμός του συμβόλου έναρξης της γραμματικής. */
%start program

%%

/* Ορισμός γραμματικών κανόνων. */

/* Δομή κώδικα. */
program:
		|	program NEWLINE
        |	program expr NEWLINE
		|   program error NEWLINE { yyerrok; wrong_expressions++; }
		|	program expr
		

/* Αριθμοί. */
number:
		INTEGER
		|	FLOAT
		|	NEG number
		;

/* Αριθμοί και αναγνωριστικά. */
term:
		IDENTIFIER          
		|	number     
		;

/* Επαναλαμβανόμενη και μη χρήση αριθμών κινούμενης υποδιαστολής, διαχωριζόμενοι με κόμμα. */
multiple_float:
		FLOAT
		|	FLOAT COMMA multiple_float
		;

/* Επαναλαμβανόμενη και μη χρήση ακέραιων αριθμών, διαχωριζόμενοι με κόμμα. */
multiple_int:
		INTEGER
		|	INTEGER COMMA multiple_int
		;

/* Επαναλαμβανόμενη και μη χρήση συμβολοσειρών, διαχωριζόμενες με κόμμα. */
string:
		STRING
		|	string COMMA STRING
		;

/* Επαναλαμβανόμενη και μη χρήση αλλαγής γραμμής. */
multiple_newline:
		NEWLINE
		|	NEWLINE multiple_newline
		;

/* Πίνακες. */
array: 
		LEFT_AR multiple_int RIGHT_AR
		|	LEFT_AR multiple_float RIGHT_AR
		|	LEFT_AR string RIGHT_AR
		|	IDENTIFIER LEFT_AR multiple_int RIGHT_AR
		|	IDENTIFIER LEFT_AR multiple_float RIGHT_AR
		|	IDENTIFIER LEFT_AR string RIGHT_AR
		;

/* Συνένωση πινάκων. */ 
array_plus:
		LEFT_AR multiple_int RIGHT_AR PLUS LEFT_AR multiple_int RIGHT_AR 
		|	LEFT_AR multiple_float RIGHT_AR PLUS LEFT_AR multiple_float RIGHT_AR
		|	LEFT_AR string RIGHT_AR PLUS LEFT_AR string RIGHT_AR
		;

/* Επαναλαμβανόμενη και μη χρήση αριθμών, αναγνωριστικών, πινάκων και συμβολοσειρών, 
   διαχωριζόμενα με κόμμα. */
values:	
		term
		| array
		| STRING
		;

multiple_values:
		values
		|	values COMMA multiple_values
		;			

/* Επαναλαμβανόμενη και μη χρήση αναγνωριστικών, διαχωριζόμενα με κόμμα. */
variable_list:
        IDENTIFIER	
        |	IDENTIFIER COMMA variable_list 
        ;

/* Δήλωση μεταβλητών. */
declaration:
		TYPE variable_list  
		|	TYPE IDENTIFIER ASSIGNOP array 
		|	TYPE IDENTIFIER ASSIGNOP number 
		|	TYPE IDENTIFIER array 
       	|	TYPE assignment
		;

/* Αναθέση τιμών. */
assignment:
		variable_list ASSIGNOP variable_list
		|	variable_list ASSIGNOP multiple_values
        ;



/* Εντολή return. */
return:            
        RETURN values
		|	RETURN arith_operation
		|	RETURN cmp_operator_multiple
		|	RETURN logical_operator_multiple
        ;

/* Συνάρτηση print (εκτύπωση μηνύματος). */
print_func:
		PRINT LEFT_PT string RIGHT_PT  
		|	PRINT LEFT_PT variable_list RIGHT_PT  
        |	PRINT LEFT_PT multiple_expressions_no_semi RIGHT_PT  
		|	PRINT LEFT_PT STRING COMMA IDENTIFIER RIGHT_PT 
		|	PRINT LEFT_PT STRING COMMA expr_no_semi RIGHT_PT
		|	PRINT LEFT_PT IDENTIFIER RIGHT_PT  
		|	PRINT LEFT_PT IDENTIFIER array RIGHT_PT
		|	PRINT LEFT_PT IDENTIFIER array LEFT_BR INTEGER RIGHT_BR RIGHT_PT  
		;

/* Συνάρτηση scan (δέχεται μια τιμή από τον χρήστη και την αποδίδει σε μία μεταβλητή). */
scan_func:
        SCAN LEFT_PT IDENTIFIER RIGHT_PT
        ;

/* Συνάρτηση len (επιστροφή μήκους πίνακα ή συμβολοσειράς). */
len_func:
	LEN LEFT_PT STRING RIGHT_PT 
        |   LEN LEFT_PT array RIGHT_PT 
       	|   LEN LEFT_PT IDENTIFIER RIGHT_PT 
        ;

/* Συνάρτηση cmp (σύγκριση δύο συμβολοσειρών). */
cmp_func:    
		CMP LEFT_PT STRING COMMA STRING RIGHT_PT 
        |	CMP LEFT_PT IDENTIFIER COMMA IDENTIFIER RIGHT_PT 
		|	CMP LEFT_PT STRING COMMA IDENTIFIER RIGHT_PT 
        |	CMP LEFT_PT IDENTIFIER COMMA STRING RIGHT_PT 
        ;

/* Δήλωση πολλαπλών μεταβλητών. */
func_multiple_types:
		TYPE IDENTIFIER COMMA TYPE IDENTIFIER
		|	TYPE IDENTIFIER COMMA func_multiple_types	
		;

/* Συνάρτηση χρήστη. */
func_def:
		FUNC IDENTIFIER LEFT_PT TYPE IDENTIFIER RIGHT_PT multiple_expressions_functions RIGHT_BR
		|	FUNC IDENTIFIER LEFT_PT func_multiple_types RIGHT_PT multiple_expressions_functions RIGHT_BR
		|	FUNC IDENTIFIER LEFT_PT RIGHT_PT multiple_expressions_functions RIGHT_BR
		;

/* Επαναλαμβανόμενη και μη χρήση εκφράσεων. */
multiple_expressions:
		expr
		|	multiple_expressions expr
		|	multiple_expressions multiple_newline expr
		;

multiple_expressions_functions:
		LEFT_BR expr
		|	NEWLINE LEFT_BR expr NEWLINE
		|	NEWLINE LEFT_BR NEWLINE multiple_expressions NEWLINE
		|	NEWLINE LEFT_BR NEWLINE multiple_expressions
		;

multiple_expressions_no_semi:
		expr_no_semi
		|	multiple_expressions_no_semi COMMA expr_no_semi
		;

/* Κλήση συνάρτησης χρήστη. */
func_call:
		IDENTIFIER LEFT_PT term COMMA term RIGHT_PT
		;

/* Συγκρίσεις. */	
cmp_operator:
		term CMP_OPERATOR term
		;

cmp_operator_multiple:
		cmp_operator
		|	cmp_operator CMP_OPERATOR term 
		|	cmp_operator CMP_OPERATOR cmp_operator_multiple 
		; 

/* Αριθμητικές εκφράσεις. */
arith_operation:
		term 
		|	arith_operation PLUS arith_operation 
        |	arith_operation MINUS arith_operation 
        |	arith_operation TIMES arith_operation 
        |	arith_operation DIVIDE arith_operation 
//		|	arith_operation MOD arith_operation
       	|	MINUS arith_operation %prec NEG 
        |	arith_operation POWER arith_operation
        |	LEFT_PT arith_operation RIGHT_PT
        ;

/* Επαυξημένες αναθέσεις. */
augmented_assignments:
		IDENTIFIER PLUS_ASSIGN term
		|	IDENTIFIER MINUS_ASSIGN term
		|	IDENTIFIER TIMES_ASSIGN term
		|	IDENTIFIER DIVIDE_ASSIGN term
		;

/* Βoolean λογική μαζί με συγκρίσεις. */
logical_operator:
        IDENTIFIER LOGIC_OPERATOR IDENTIFIER
        |	LOG_NOT IDENTIFIER
        |	cmp_operator LOGIC_OPERATOR cmp_operator
        |	LOG_NOT RIGHT_PT cmp_operator LEFT_PT
        ;

logical_operator_multiple:
        logical_operator
        |	logical_operator LOGIC_OPERATOR IDENTIFIER
        |	LOG_NOT RIGHT_PT logical_operator LEFT_PT
        |	logical_operator LOGIC_OPERATOR logical_operator_multiple
        ;

/* Δήλωση if. */
if_func:
		IF LEFT_PT cmp_operator_multiple RIGHT_PT expr_no_semi
		|   IF LEFT_PT logical_operator_multiple RIGHT_PT expr_no_semi
        ;

if_multiple_func:
		IF LEFT_PT cmp_operator_multiple RIGHT_PT multiple_expressions_functions RIGHT_BR
		|   IF LEFT_PT logical_operator_multiple RIGHT_PT multiple_expressions_functions RIGHT_BR
		;

/* Δήλωση while. */
while_func:
		WHILE LEFT_PT cmp_operator_multiple RIGHT_PT multiple_expressions_functions RIGHT_BR
		|   WHILE LEFT_PT logical_operator_multiple RIGHT_PT multiple_expressions_functions RIGHT_BR       
        ;

/* Δήλωση for. */
for_func:
		FOR LEFT_PT assignment SEMICOLON cmp_operator_multiple SEMICOLON plus_minus RIGHT_PT multiple_expressions_functions RIGHT_BR
	    |	FOR LEFT_PT assignment SEMICOLON logical_operator_multiple SEMICOLON plus_minus RIGHT_PT multiple_expressions_functions RIGHT_BR
        ;

/* Έντολή προσαύξησης και μείωσης κατά ένα. */
plus_minus:
		DOUBLE_PLUS term
		|	DOUBLE_MINUS term
		|	term DOUBLE_PLUS
		|	term DOUBLE_MINUS
		;

/* Ανάθεση τιμών με τη χρήση εκφράσεων. */
expr_assignment:
		IDENTIFIER ASSIGNOP arith_operation 
		|	IDENTIFIER ASSIGNOP cmp_operator_multiple
		|	IDENTIFIER ASSIGNOP logical_operator_multiple			
		|	IDENTIFIER ASSIGNOP array_plus
		|	IDENTIFIER ASSIGNOP values
		|	IDENTIFIER ASSIGNOP cmp_func
		|	IDENTIFIER ASSIGNOP len_func
		;

/* Εκφράσεις που δεν απαιτούν σύμβολο διαχωρισμού εντολών. */
expr_no_semi:
		scan_func 			
		|	len_func			
		|	print_func			
		|	cmp_func			
		|	declaration 	
		|	cmp_operator_multiple
        |   logical_operator_multiple	
		|	if_func 
        |   return
		|	arith_operation
		|	augmented_assignments
		|	plus_minus
		;

/* Σύνολο εκφράσεων με σύμβολο διαχωρισμού εντολών και συναρτήσεις-δηλώσεις. */
expr:
		expr_no_semi SEMICOLON			{ correct_expressions++; }
		|	expr_assignment SEMICOLON	{ correct_expressions++; }
        |	assignment SEMICOLON		{ correct_expressions++; }       
		|	func_call SEMICOLON   		{ correct_expressions++; }
		|	array SEMICOLON 			{ correct_expressions++; }
		|	array_plus SEMICOLON 		{ correct_expressions++; }
		|	while_func 					{ correct_expressions++; }
		|	for_func					{ correct_expressions++; }
		|	func_def           			{ correct_expressions++; }		
		|	if_multiple_func			{ correct_expressions++; }
		;
        
%%

/* Επιπλέον κώδικας σε γλώσσα C. */

/* Η συνάρτηση main, αποτελεί το σημείο εκκίνησης του προγράμματος. */
int main(int argc, char **argv) {
	/* Έλεγχος ορισμάτων εκτέλεσης.
	   Αν είναι 3 (argv[2]): το πρόγραμμα διαβάζει από το αρχείο του 2ου ορίσματος και γράφει στο αρχείο του 3ου.
	   Αν είναι 2 (argv[1]): το πρόγραμμα διαβάζει από το αρχείο του 2ου ορίσματος και γράφει στην οθόνη.
	   Το 1ο όρισμα (argv[0]) αποτελεί το όνομα του εκτελέσιμου αρχείου. */
	if (argc == 3) {
		if (!(yyin = fopen(argv[1], "r"))) {
			fprintf(stderr, "Cannot read file: %s\n", argv[1]);
			return 1;
		}
		if (!(yyout = fopen(argv[2], "w"))) {
			fprintf(stderr, "Cannot create file: %s\n", argv[2]);
			fclose(yyin);
			return 1;
		}
	} else if (argc == 2) {
		if (!(yyin = fopen(argv[1], "r"))) {
			fprintf(stderr, "Cannot read file: %s\n", argv[1]);
			return 1;
		}
        yyout = stdout;
	} else {
		fprintf(stderr, "Usage: %s input (output)\n", *argv);
		return 2;
	}

	/* Γίνεται έλεγχος των ορισμάτων της γραμμής εντολών και κλήση της yyparse
	   που πραγματοποιεί τη συντακτική ανάλυση. Ελέγχεται και εμφανίζεται η 
       επιτυχής ή μη συντακτική ανάλυση. */
	int ret = yyparse();
	if (wrong_expressions==0 && ret==0) { 
		printf("\tBison -> PARSING SUCCEEDED.\n");
   		if (par_warn > 0) printf(" (with %d warning(s))\n", par_warn);
    	printf("\n");
	} else {
    	printf("\tBison -> PARSING FAILED (%d syntax error(s) found).\n", wrong_expressions);
	} 
		/* Εμφανίζονται τα πλήθη των σωστών και λανθασμένων λέξεων και εκφράσεων. */ 
		fprintf(yyout, "\nCorrect Words: %d\n", correct_words);
		fprintf(yyout, "Correct Expressions: %d\n", correct_expressions);
		fprintf(yyout, "Wrong Words: %d\n", wrong_words);
		fprintf(yyout, "Wrong Expressions: %d\n", wrong_expressions);

	/* Κλείσιμο των αρχείων που χρησιμοποιήθηκαν για την εκτέλεση του προγράμματος. */
	if (yyin) fclose(yyin);
	if (yyout && yyout != stdout) fclose(yyout);
	
	return 0;
	
}