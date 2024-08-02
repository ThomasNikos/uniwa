/* 
Onoma arxeiou:	calc-0_with_flex.y
Perigrafh:	Bison arxeio gia syntaktiko elegxo postfix arithmhtikwn ekfrasewn me error handling
Syggrafeas:	Ergasthrio Metaglwttistwn
 
*/

%{

/* ______________________________________________________________
Orismoi kai dhlwseis glwssas C. Otidhpote exei na kanei me orismo h arxikopoihsh  metablhtwn, arxeia header kai dhlwseis #define mpainei se auto to shmeio 
_______________________________________________________________*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int line;
int flag=0;
extern char * yytext;
extern int lex_warn;
int par_warn=0;
#define YYSTYPE int
int yylex();
void yyerror (const char *msg);
%}

/* ____________________________________________ 
Orismos twn anagnwrisimwn lektikwn monadwn. 
___________________________________________*/

%token INTEGER NEWLINE TOKEN_ERROR

/* _________________________________________
Orismos tou symbolou enarkshs ths grammatikhs 
_____________________________________________*/

%start program

%%

/*____________________________________________
   Orismos twn grammatikwn kanonwn. 
______________________________________________*/
					    
program:
        program expr NEWLINE { printf("%d\n", $2); }
        | program error NEWLINE { printf("\tERROR !\n"); yyerrok; 
											flag++;}
        | program expr expr TOKEN_ERROR NEWLINE { 
                                    printf("\tTOKEN_ERROR !\n"); }
        |
        ;
expr:
        INTEGER          { $$ = atoi(yytext); }
        | expr expr '+' { $$ = $1 + $2; }
		| expr expr TOKEN_ERROR '+' {printf("\tWarning: Unknown operator ignored!\n");
									$$ = $1 + $2; par_warn++;}
        | expr expr '*' { $$ = $1 * $2; }
		;

%%

/* __________________________________________________

 Epiprosthetos kwdikas-xrhsth se glwssa C pou tha symperilhfthei ston kwdika tou syntaktikoy analyth */


int main(int argc,char **argv)
{
 int i;
 
 int ret = yyparse();

 if (flag==0 && ret==0)
	printf("\t\tBison -> PARSING SUCCEEDED.\n");
	if (par_warn>0)printf("(with %d warning(s))\n\n", par_warn);
 else
	printf("\t\tBison -> PARSING FAILED (%d syntax error(s) found).\n", flag);

 return 0;
}
