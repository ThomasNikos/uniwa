/* Onoma arxeiou:	scanner.l
   Perigrafh:		Aplos lektikos analyths me diaxeirisi 					lathoys	
   SyggrafeasQ		Co lab
   
*/

%option noyywrap
%x error

%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "token.h" //Header file pou periexei ola ta tokens 

/* Orismos metrhth trexousas grammhs */
int line=1;

void ERROR(const char *msg); //synartisi diaxeirisis lathwn
void prn(char *s);

%}

DELIMITERS	[ \t]+
INTEGER 	[0-9]+
INTEGER_ERROR	{INTEGER}[A-Za-z]+

%%

"+"			{prn("PLUS"); return PLUS;}
{DELIMITERS}	{}
\n 			{line++;}
{INTEGER}		{prn("INTCONST"); return INTCONST;}
{INTEGER_ERROR}	{ERROR("Integer ends with letter!"); return TOKEN_ERROR;}
.		{ERROR("Unrecognized token error!"); BEGIN(error); return TOKEN_ERROR;}
<error>[ \t\n]	{BEGIN(0);}
<error>.		{}



%%

void ERROR(const char *msg)
{
        fprintf(yyout, "\tFlex -> ERROR, line %d at lexeme \'%s\' : %s\n",line, yytext, msg);
}

/* H synarthsh typwnei sthn othonh to keimeno tou anagnwristikou pou tairiakse me kapoion kanona. Xrhsimopoieitai kathara gia logous katanohshs kai debugging. */
void prn(char *s)
{
	printf("\tFlex -> Matched token: %s %s\n", yytext, s);
}


