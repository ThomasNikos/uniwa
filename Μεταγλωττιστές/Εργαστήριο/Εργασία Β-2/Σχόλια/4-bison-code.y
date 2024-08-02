/* ¨Ονομα αρχείου:	4-bison-code.y

   Περιγραφή:	Απλός συναντικός αναλυτής με τη χρήση Bison. 

   Συγγαφέας:	Ομάδα Α4 - Τμήματος Α3 Εργαστηρίου Μετταγλωτιστών

   Σχόλια:		Ο συντακτικός αναλυτής αναγνωρίζει: 
				1) Dhlwsh metablhths typou integer =========> int a;
				2) Anathesh timhs akeraiou se metablhth ====> a = 5;
				3) Anathesh timhs metablthhs se metablhth ==> a = b;
				Katanoei kai xrhsimopoiei stous grammatikous kanones tis akolouthes
				lektikes monades pou parexontai/anagnwrizontai apo to ergaleio Flex:
				1) SINT		H leksh "int" gia orismo metablhths integer
				2) SEMI		O xarakthras ';' ws termatikos entolhs
				3) ASSIGNOP	O xarakthras '=' gia tis anatheseis timwn
				4) IDENTIFIER	Anagnwristiko / onoma metablhths
				5) INTCONST	Akeraios arithmos
				Ανιχνεύονται συντακτικά λάθη και εμφανίζονται στην οθόνη η τρέχουσα γραμμή και ένα μήνυμα λάθους.
				
   Οδηγίες εκτέλεσης:	Εισαγωγή της λέξης make στον τρέχον κατάλογο ή
						bison -d 4-bison-code.y
						flex 4-bison-code.l
						gcc 4-bison-code.tab.c lex.yy.c -o 4-bison-code  -lm
                        και ./4-bison-code input.txt output.txt (για εκτέλεση σε Linux)
						ή 4-bison-code input.txt output.txt (για εκτέλεση σε Windows)
*/

/* Ορισμοί και δηλώσεις γλώσσας C. */
%{

/* Δήλωση των header files (αρχείων επικεφαλίδας) και δηλώση σταθεράς. */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double
	//#define YYDEBUG 1 //DEBUGGING


/* Ο δείκτης yyin είναι αυτός που δείχενει στο αρχείο εισόδου. */

    extern int yylex(void);
    extern FILE *yyin, *yyout;

	extern int correct_words;
	extern int wrong_words;
	int correct_expressions = 0;
	int wrong_expressions = 0;
	int par_warn=0;

/* Η συνάρτηση yyerror χρησιμοποιείται για την αναφορά σφαλμάτων. Καλείται από την 
   yyparse όταν υπάρξει κάποιο συντακτικό λάθος. */

void yyerror (const char *msg);
%}

/* Δηλώσεις και ορισμοί Bison */

/* Ορισμός των λεκτικών μονάδων. */

%token DELIMITER IDENTIFIER KEYWORD STRING INTEGER FLOAT PLUS MINUS TIMES DIVIDE POWER COMMENT NEG
%token UNKNOWN_TOKEN NEWLINE MINUS_ASSIGN PLUS_ASSIGN TIMES_ASSIGN MOD BACKSLASH_NEWLINE DIVIDE_ASSIGN 
%token PRINT LEFT_PT RIGHT_PT SEMICOLON ASSIGNOP CMP_OPERATOR TYPE SCAN LEN CMP COMMA FUNC LEFT_BR RIGHT_BR 
%token IF WHILE FOR RETURN DOUBLE_PLUS DOUBLE_MINUS LOGIC_OPERATOR LOG_NOT RIGHT_AR LEFT_AR AMPERSAND 

/* ΠΡΟΤΕΡΑΙΟΤΗΤΕΣ */ 
%left PLUS MINUS
%left TIMES DIVIDE
%left NEG
%right POWER
%left LEFT_PT RIGHT_PT


/* Ορισμός του συμβόλου έναρξης της γραμματικής. */
%start program

%%

/* Ορισμός των γραμματικών κανόνων. */

program:
		|	program NEWLINE
        |	program expr NEWLINE
		|   program error NEWLINE { printf("\tERROR !\n"); yyerrok; wrong_expressions++; }
		|	program expr
		;

number:
		INTEGER
		|	FLOAT
		|	NEG number
		;

term:
		IDENTIFIER          
		|	number     
		;

multiple_float:
		FLOAT
		|	FLOAT COMMA multiple_float
		;

multiple_int:
		INTEGER
		|	INTEGER COMMA multiple_int
		;

multiple_newline:
		NEWLINE
		|	NEWLINE multiple_newline
		;

array: 
		LEFT_AR multiple_int RIGHT_AR
		|	LEFT_AR multiple_float RIGHT_AR
		|	LEFT_AR string RIGHT_AR
		|	IDENTIFIER LEFT_AR multiple_int RIGHT_AR
		|	IDENTIFIER LEFT_AR multiple_float RIGHT_AR
		|	IDENTIFIER LEFT_AR string RIGHT_AR
		;

array_plus:
		LEFT_AR multiple_int RIGHT_AR PLUS LEFT_AR multiple_int RIGHT_AR 
		|	LEFT_AR multiple_float RIGHT_AR PLUS LEFT_AR multiple_float RIGHT_AR
		|	LEFT_AR string RIGHT_AR PLUS LEFT_AR string RIGHT_AR
		;

values:	
		term
		| array
		| STRING
		;

multiple_values:
		values
		|	values COMMA multiple_values
		;			

variable_list:
        IDENTIFIER		//a
        |	IDENTIFIER COMMA variable_list 
        ;

assignment:
		|	variable_list ASSIGNOP variable_list  //a, b = a, b //  a = 0
		|	variable_list ASSIGNOP multiple_values
        ;

string:
		STRING
		|	string COMMA STRING
		;		

ret:            
        RETURN INTEGER
        |	RETURN IDENTIFIER
        ;

print_func:
		PRINT LEFT_PT string RIGHT_PT  
		|	PRINT LEFT_PT variable_list RIGHT_PT  
        |	PRINT LEFT_PT multiple_expressions_no_semi RIGHT_PT  
		|	PRINT LEFT_PT STRING COMMA IDENTIFIER RIGHT_PT 
		|	PRINT LEFT_PT STRING COMMA expr_no_semi RIGHT_PT
		|	PRINT LEFT_PT IDENTIFIER RIGHT_PT  
		|	PRINT LEFT_PT IDENTIFIER array RIGHT_PT  
		;

scan_func:
        SCAN LEFT_PT IDENTIFIER RIGHT_PT
        ;

declaration:
		TYPE variable_list  
		|	TYPE array 
       	|	TYPE assignment
		;

multiple_expressions_functions:
		LEFT_BR expr
		|	NEWLINE LEFT_BR expr NEWLINE
		|	NEWLINE LEFT_BR NEWLINE multiple_expressions NEWLINE
		|	NEWLINE LEFT_BR NEWLINE multiple_expressions
		;

multiple_expressions:
		expr
		|	multiple_expressions expr
		|	multiple_expressions multiple_newline expr
		;

multiple_expressions_no_semi:
		expr_no_semi
		|	multiple_expressions_no_semi COMMA expr_no_semi
		;

len_func:
	LEN LEFT_PT STRING RIGHT_PT 
        |   LEN LEFT_PT array RIGHT_PT 
       	|   LEN LEFT_PT IDENTIFIER RIGHT_PT 
        ;

cmp_func:    
		CMP LEFT_PT STRING COMMA STRING RIGHT_PT 
        |	CMP LEFT_PT IDENTIFIER COMMA IDENTIFIER RIGHT_PT 
		|	CMP LEFT_PT STRING COMMA IDENTIFIER RIGHT_PT 
        |	CMP LEFT_PT IDENTIFIER COMMA  STRING RIGHT_PT 
        |	CMP LEFT_PT number COMMA number RIGHT_PT 
        ;

func_def:
		FUNC IDENTIFIER LEFT_PT TYPE IDENTIFIER COMMA TYPE IDENTIFIER RIGHT_PT multiple_expressions_functions RIGHT_BR
		;

func_call:
		IDENTIFIER LEFT_PT term COMMA term RIGHT_PT 
		;
		
cmp_operator:
		term CMP_OPERATOR term                       // A > B
		;

cmp_operator_multiple:
		cmp_operator
		|	cmp_operator CMP_OPERATOR term 
		|	cmp_operator CMP_OPERATOR cmp_operator_multiple 
		; 

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

augmented_assignments:
		IDENTIFIER PLUS_ASSIGN term
		|	IDENTIFIER MINUS_ASSIGN term
		|	IDENTIFIER TIMES_ASSIGN term
		|	IDENTIFIER DIVIDE_ASSIGN term
		;

logical_operator:
        IDENTIFIER LOGIC_OPERATOR IDENTIFIER            // a || b // a && b
        |	LOG_NOT IDENTIFIER                      // ! a
        |	cmp_operator LOGIC_OPERATOR cmp_operator// a < b && c <= d // 1 > 2 && 3 > 4
        |	LOG_NOT RIGHT_PT cmp_operator LEFT_PT   // ! ( a > b )
        ;


logical_operator_multiple:
        logical_operator
        |	logical_operator LOGIC_OPERATOR IDENTIFIER // a && b || c
        |	LOG_NOT RIGHT_PT logical_operator LEFT_PT // !(a || b)
        |	logical_operator LOGIC_OPERATOR logical_operator_multiple // a && b || c || b
        ;

if_func:
		IF LEFT_PT cmp_operator_multiple RIGHT_PT expr_no_semi        // if (a > b) entolh (1);
		|	IF LEFT_PT cmp_operator_multiple RIGHT_PT LEFT_BR multiple_expressions RIGHT_BR // if (a > b > c) { entoles (1+)}
		|   IF LEFT_PT logical_operator_multiple RIGHT_PT expr_no_semi // if (a || b) entolh (1)
        |   IF LEFT_PT logical_operator_multiple RIGHT_PT LEFT_BR multiple_expressions RIGHT_BR // if (a > b || c) { entoles (1+)}
        ;

while_func:
		WHILE LEFT_PT cmp_operator_multiple RIGHT_PT multiple_expressions_functions RIGHT_BR
		|   WHILE LEFT_PT logical_operator_multiple RIGHT_PT multiple_expressions_functions RIGHT_BR       
        ;

for_func:
		FOR LEFT_PT assignment SEMICOLON cmp_operator_multiple SEMICOLON plus_minus RIGHT_PT multiple_expressions_functions RIGHT_BR
	    |	FOR LEFT_PT assignment SEMICOLON logical_operator_multiple SEMICOLON plus_minus RIGHT_PT multiple_expressions_functions RIGHT_BR
        ;                                                                            // ++ --

plus_minus:
		DOUBLE_PLUS term
		|	DOUBLE_MINUS term
		|	term DOUBLE_PLUS
		|	term DOUBLE_MINUS
		;

expr_assignment:
		IDENTIFIER ASSIGNOP arith_operation 
		|	IDENTIFIER ASSIGNOP cmp_operator_multiple
		|	IDENTIFIER ASSIGNOP logical_operator_multiple			
		|	IDENTIFIER ASSIGNOP array_plus
		|	IDENTIFIER ASSIGNOP values
		;

return:
		RETURN values
		;

expr_no_semi:
		scan_func 			
		|	len_func			
		|	print_func			
		|	cmp_func			
		|	declaration 	
		|	cmp_operator_multiple
        |   logical_operator_multiple	
		|	if_func 
        |   ret
		|	arith_operation
		|	augmented_assignments
		;

expr:
		expr_no_semi SEMICOLON			{ correct_expressions++; }
		|	print_func SEMICOLON		{ correct_expressions++; }
		|	expr_assignment SEMICOLON	{ correct_expressions++; }
        |	assignment SEMICOLON		{ correct_expressions++; }
        |	func_def           			{ correct_expressions++; }
		|	func_call SEMICOLON   		{ correct_expressions++; }
		|	arith_operation SEMICOLON  	{ correct_expressions++; }
		|	while_func 					{ correct_expressions++; }
		|	for_func					{ correct_expressions++; }
		|	array SEMICOLON 			{ correct_expressions++; }
		|	array_plus SEMICOLON 		{ correct_expressions++; }
		|	return SEMICOLON			{ correct_expressions++; }
		;
        
%%

/* Επιπλέον κώδικας σε γλώσσα C. */

/* Η συνάρτηση main, αποτελεί το σημείο εκκίνησης του προγράμματος. */

int main(int argc, char **argv) {
	//yydebug=1;

	/* Έλεγχος ορισμάτων γραμμής εντολών.
	   Αν είναι 3 (argv[2]): το πρόγραμμα διαβάζει απο το απο το αρχείο του 2ου ορίσματος και γράφει στο αρχείο του 3ου.
	   Αν είναι 2 (argv[1]): το πρόγραμμα διαβάζει απο το απο το αρχείο του 2ου ορίσματος και γράφει στην οθόνη.
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
   		printf("\t\tBison -> PARSING SUCCEEDED.\n");
   		if (par_warn > 0) printf(" (with %d warning(s))\n", par_warn);
    	printf("\n");
	} else {
    	printf("\t\tBison -> PARSING FAILED (%d syntax error(s) found).\n", wrong_expressions);
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