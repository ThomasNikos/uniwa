/* Onoma arxeiou:       4-bison-code.y
   Perigrafh:           Ypodeigma gia anaptyksh syntaktikou analyth me xrhsh tou ergaleiou Bison
   Syggrafeas:          Ergasthrio Metaglwttistwn, Tmhma Mhxanikwn Plhroforikhs kai Ypologistwn,
                        Panepisthmio Dytikhs Attikhs
   Sxolia:              To paron programma ylopoiei (me th xrhsh Bison) enan aplo syntaktiko analyth
			pou anagnwrizei thn prosthesh akeraiwn arithmwn (dekadikou systhmatos) & metablhtwn
			kai ektypwnei to apotelesma sthn othonh (thewrontas oti oi metablhtes exoun
			panta thn timh 0). Leitourgei autonoma, dhladh xwris Flex kai anagnwrizei kena
			(space & tab), akeraious (dekadikou systhmatos) kai onomata metablhtwn ths glwssas
			Uni-C enw diaxeirizetai tous eidikous xarakthres neas grammhs '\n' (new line)
			kai 'EOF' (end of file). Kathara gia logous debugging typwnei sthn othonh otidhpote
			epistrefei h synarthsh yylex().
   Odhgies ekteleshs:   Dinete "make" xwris ta eisagwgika ston trexonta katalogo. Enallaktika:
			bison -o simple-bison-code.c simple-bison-code.y
                        gcc -o simple-bison-code simple-bison-code.c
                        ./simple-bison-code
*/

%{
/* Orismoi kai dhlwseis glwssas C. Otidhpote exei na kanei me orismo h arxikopoihsh
   metablhtwn & synarthsewn, arxeia header kai dhlwseis #define mpainei se auto to shmeio */
        #include <stdio.h>
		#include <stdlib.h>
		//#define YYDEBUG 1 //DEBUGGING

        extern int yylex(void);
        extern FILE *yyin, *yyout;

		extern int correct_words;
		extern int wrong_words;
		int correct_expressions = 0;
		int wrong_expressions = 0;

        void yyerror(char *);
%}

/* Orismos twn anagnwrisimwn lektikwn monadwn. */
%token DELIMITER IDENTIFIER KEYWORD STRING INTEGER FLOAT ARITH_OPERATOR COMMENT UNKNOWN_TOKEN NEWLINE/* FILL ME */
%token ARRAY PRINT LEFT_PT RIGHT_PT SEMICOLON ASSIGNOP CMP_OPERATOR TYPE SCAN LEN CMP COMMA FUNC LEFT_BR RIGHT_BR
%token IF WHILE FOR DOUBLE_PLUS DOUBLE_MINUS

%start program

%%

program:
        |	program NEWLINE 
        |	program expr 
        ;

number:
		INTEGER
		|	FLOAT
		|	ARITH_OPERATOR number
		;

term:
		IDENTIFIER
		|	number
		|	IDENTIFIER ARRAY
		;	

multiple_term:
		term
		| term COMMA term
		;			

string:
		STRING
		|	string COMMA STRING
		;			

print_func:
		PRINT LEFT_PT string RIGHT_PT  
		|	PRINT LEFT_PT variable_list RIGHT_PT  
        |	PRINT LEFT_PT multiple_expressions_no_semi RIGHT_PT  
		|	PRINT LEFT_PT STRING COMMA IDENTIFIER RIGHT_PT 
		|	PRINT LEFT_PT STRING COMMA expr_no_semi RIGHT_PT 
		|	PRINT LEFT_PT IDENTIFIER RIGHT_PT  
		|	PRINT LEFT_PT IDENTIFIER ARRAY RIGHT_PT  
		;

declaration:
        TYPE IDENTIFIER  
        ;

assignment:
		variable_list ASSIGNOP expr_no_semi 
		|	variable_list ASSIGNOP multiple_term 
		|	variable_list ASSIGNOP variable_list 
        ;

multiple_expressions:
		expr
		|	multiple_expressions expr
		;

multiple_expressions_no_semi:
		expr_no_semi
		|	multiple_expressions_no_semi COMMA expr_no_semi
		;

variable_list:
        IDENTIFIER
        | variable_list COMMA IDENTIFIER
        ;

scan_func:
        SCAN LEFT_PT IDENTIFIER RIGHT_PT
        ;

len_func:
		LEN LEFT_PT STRING RIGHT_PT 
        |   LEN LEFT_PT ARRAY RIGHT_PT 
        |   LEN LEFT_PT IDENTIFIER RIGHT_PT 
        ;

cmp_func:    
		CMP LEFT_PT STRING COMMA STRING RIGHT_PT 
        |   CMP LEFT_PT IDENTIFIER COMMA IDENTIFIER RIGHT_PT 
		|	CMP LEFT_PT STRING COMMA IDENTIFIER RIGHT_PT 
        |   CMP LEFT_PT IDENTIFIER COMMA STRING RIGHT_PT 
        |   CMP LEFT_PT number COMMA number RIGHT_PT 
        ;

func_def:
		FUNC IDENTIFIER LEFT_PT TYPE IDENTIFIER COMMA TYPE IDENTIFIER RIGHT_PT LEFT_BR RIGHT_BR
		;

func_call:
		IDENTIFIER LEFT_PT term COMMA term RIGHT_PT 
		;
		
cmp_operator:
		term CMP_OPERATOR term
		;

cmp_operator_multiple:
		cmp_operator
		|	cmp_operator CMP_OPERATOR term
		|	cmp_operator CMP_OPERATOR cmp_operator_multiple
		;

arith_operation:
		term ARITH_OPERATOR term
		;

if_func:
		IF LEFT_PT cmp_operator_multiple RIGHT_PT expr_no_semi
		| IF LEFT_PT cmp_operator_multiple RIGHT_PT LEFT_BR multiple_expressions RIGHT_BR 
		;

while_func:
		WHILE LEFT_PT cmp_operator_multiple RIGHT_PT NEWLINE LEFT_BR NEWLINE multiple_expressions NEWLINE RIGHT_BR
		;

for_func:
		FOR LEFT_PT assignment	SEMICOLON cmp_operator_multiple SEMICOLON plus_minus RIGHT_PT NEWLINE LEFT_BR NEWLINE multiple_expressions NEWLINE RIGHT_BR
		;

plus_minus:
		DOUBLE_PLUS term
		|	DOUBLE_MINUS term
		|	term DOUBLE_PLUS
		|	term DOUBLE_MINUS
		;

array:
		ARRAY
		|	ARRAY ARITH_OPERATOR ARRAY	
		;

expr_no_semi:
		scan_func 			
		| len_func			
		| print_func			
		| cmp_func			
		| declaration 	
		| cmp_operator_multiple	
		| if_func 
		;

expr:
		expr_no_semi SEMICOLON			{ correct_expressions++; }
        |   assignment SEMICOLON		{ correct_expressions++; }
        |   func_def SEMICOLON          { correct_expressions++; }
		|   func_call SEMICOLON   		{ correct_expressions++; }
		|	arith_operation SEMICOLON  	{ correct_expressions++; }
		|	array SEMICOLON 			{ correct_expressions++; }
		|	while_func					{ correct_expressions++; }
		|	for_func 					{ correct_expressions++; }
		;
        
%%

/* H synarthsh yyerror xrhsimopoieitai gia thn anafora sfalmatwn. Sygkekrimena kaleitai
   apo thn yyparse otan yparksei kapoio syntaktiko lathos. Sthn parakatw periptwsh h
   synarthsh epi ths ousias typwnei mhnyma lathous sthn othonh. */
void yyerror(char *s) {
        fprintf(stderr, "Error: %s\n", s);
}



int main(int argc, char **argv) {
	//yydebug=1; DEBUGGING
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

    yyparse();

	fprintf(yyout, "\nCorrect Words: %d\n", correct_words);
	fprintf(yyout, "Correct Expressions: %d\n", correct_expressions);
	fprintf(yyout, "Wrong Words: %d\n", wrong_words);
	fprintf(yyout, "Wrong Expressions: %d\n", wrong_expressions);

	/* Κλείσιμο των αρχείων που χρησιμοποιήθηκαν για την εκτέλεση του προγράμματος */
	if (yyin) fclose(yyin);
	if (yyout && yyout != stdout) fclose(yyout);
	
	return 0;
	
}