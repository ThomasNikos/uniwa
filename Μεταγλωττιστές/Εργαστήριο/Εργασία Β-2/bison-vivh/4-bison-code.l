%option noyywrap 
%x error

%{		

#include <stdio.h>	 
#include <stdlib.h>	
#include <string.h>
#include "4-bison-code.tab.h"	

int lex_warn = 0;

int line=1;

void yyerror (const char *msg);
void prn(char *s);

int correct_words = 0;
int wrong_words = 0;

%}

DELIMITER		([ \t]+) 
IDENTIFIER		[a-zA-Z]+((_+)*([0-9]+)*([a-zA-Z]+)*)*|_+((_+)*([0-9]+)*([a-zA-Z]+)*)*
KEYWORD			break|case|func|const|continue|do|else|long|return|sizeof|struct|switch|void
TYPE            double|int|long|short|float
STRING			\"(([^\"\n\\])*(\\\")*(\\n)*(\\\\)*)*\" 
INTEGER			[1-9]([0-9]+)?|0[xX][a-fA-F0-9]+|0[0-7]*
FLOAT				[0-9]+[eE]-?[0-9]+(\.[0-9]+)?|[0-9]+\.[0-9]+([eE]-?[0-9]+(\.[0-9]+)?)?
CMP_OPERATOR	">"|"<"|"<="|">="|"=="|"!="
LOGIC_OPERATOR	"&&"|"||"
COMMENT			\/\/.*\n|\/\*(.*\n*)*?\*\/
UNKNOWN_TOKEN	.

%%				

"print"		   { prn("PRINT"); correct_words++; return PRINT;}
"scan"         { prn("SCAN"); correct_words++; return SCAN; }
"len"          { prn("LEN"); correct_words++; return LEN; }
"cmp"          { prn("CMP"); correct_words++; return CMP; }
"func"         { prn("FUNC"); correct_words++; return FUNC; }	
"if"			{ prn("IF"); correct_words++; return IF; }	
"while"        { prn("WHILE"); correct_words++; return WHILE; }	
"for"			{ prn("FOR"); correct_words++; return FOR; }		
"return"		{ prn ("RETURN"); correct_words++; return RETURN; }	

"["				{ prn ("LEFT_AR"); correct_words++; return LEFT_AR ; }
"]"				{ prn ("RIGHT_AR"); correct_words++; return RIGHT_AR ; }
"(" 				{ prn("LEFT_PT"); return LEFT_PT; }
")" 		   	{ prn("RIGHT_PT"); return RIGHT_PT; }
"{" 				{ prn("LEFT_BR"); return LEFT_BR; }
"}" 		   	{ prn("RIGHT_BR"); return RIGHT_BR; }
"+" 				{ prn("PLUS"); return PLUS; }
"-" 				{ prn("MINUS"); return MINUS; }
"*" 				{ prn("TIMES"); return TIMES; }
"/" 				{ prn("DIVIDE"); return DIVIDE; }
"^"	 			{ prn("POWER"); return POWER; }
";"            { prn("SEMICOLON"); return SEMICOLON; }
","            { prn("COMMA"); return COMMA; }
"="				{ prn("ASSIGNOP"); return ASSIGNOP; }
"++"				{ return DOUBLE_PLUS; }
"--"				{ return DOUBLE_MINUS; }
"!"				{ prn ("LOGIC_OPERATOR"); return LOG_NOT; }
"&"            { prn("AMPERSAND"); return '&'; }
"\n"			{prn("NEWLINE"); line++; return NEWLINE;}
"\\\n"			{line++;}

{DELIMITER}		{ /* ignore whitespace */ }	
{KEYWORD}		{ correct_words++; return KEYWORD; }							
{TYPE}			{ prn("TYPE"); correct_words++; return TYPE; }
{IDENTIFIER}	{ prn("IDENTIFIER"); correct_words++; return IDENTIFIER; }	
{STRING}		{ prn("STRING"); correct_words++; return STRING; }  			   
{INTEGER}		{ prn("INTEGER"); correct_words++; return INTEGER; } 			
{FLOAT}			{ prn("FLOAT"); correct_words++; return FLOAT; }        				
{CMP_OPERATOR}	{ prn("CMP_OPERATOR"); return CMP_OPERATOR; } 		
{LOGIC_OPERATOR}	{ prn ("LOGIC_OPERATOR"); return LOGIC_OPERATOR; }			
{COMMENT}		{ 
                    char *c = yytext;
                    while (*c) {
                        if (*c == '\n') line++;
                        c++;
                    }
                }					    						
{UNKNOWN_TOKEN}	{ yyerror ("Unrecognized character(s) encountered!"); lex_warn++; wrong_words++; BEGIN(error); }							  											

<error>[ \t]+   { BEGIN(0); printf("\t\t%d character(s) ignored so far\n", lex_warn); }
<error>.        {  lex_warn++; }
<error>\n       { BEGIN(0); line++; printf("\t\t%d character(s) ignored so far\n", lex_warn); return NEWLINE; }


%%			

void yyerror (const char *msg)
{
    fprintf(yyout, "\tLine %d at lexeme \'%s\' : %s\n",line, yytext, msg);
}

void prn(char *s)
{
    printf("\tLine: %d Flex -> Matched token: %s\n", line, yytext);
	return;
}