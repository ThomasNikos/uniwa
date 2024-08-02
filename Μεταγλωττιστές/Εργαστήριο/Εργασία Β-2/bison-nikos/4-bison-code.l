/* Όνομα αρχείου: 4-bison-code.l

/* Η ανάγνωση περιορίζεται σε ένα μόνο αρχείο και τερματίζει στο πρώτο EOF. 
   Αγνοείται η µη ύπαρξη της yywrap και να µη χρειάζεται ο διακόπτης -lfl. */
%option noyywrap 

/* Τμήμα ορισμών κώδικα C. 
   Οτιδήποτε μεταξύ των %{ και %} μεταφέρεται αυτούσιο στο αρχείο .c που θα δημιουργήσει το Flex. */
%{		

/* Δήλωση των header files (αρχείων επικεφαλίδας) */
#include <stdio.h>	 
#include <stdlib.h>	
#include <string.h>
/* Αρχείο (token.h) που περιέχει τη λίστα με όλες τις λεκτικές μονάδες */
#include "4-bison-code.tab.h"	

void prn(char *s);

int correct_words = 0;
int wrong_words = 0;

%}

/* Ορισμοί ονομάτων Κανονικών Εκφράσεων (ΚΕ): Αριστερά όνομα - Δεξιά ΚΕ */
DELIMITER		[ \t]+
IDENTIFIER		[a-zA-Z]+((_+)*([0-9]+)*([a-zA-Z]+)*)*|_+((_+)*([0-9]+)*([a-zA-Z]+)*)*
KEYWORD			break|case|func|const|continue|do|else|for|if|long|return|sizeof|struct|switch|void|while
TYPE           	double|int|long|short|float
STRING			\"(([^\"\n\\])*(\\\")*(\\n)*(\\\\)*)*\"
INTEGER			[1-9]([0-9]+)?|0[xX][a-fA-F0-9]+|0[0-7]*
FLOAT			[0-9]+[eE]-?[0-9]+(\.[0-9]+)?|[0-9]+\.[0-9]+([eE]-?[0-9]+(\.[0-9]+)?)?
ARITH_OPERATOR	"+"|"-"|"*"|"/"
CMP_OPERATOR	">"|"<"|"<="|">="|"=="|"!="
COMMENT			\/\/.*\n|\/\*(.*\n*)*?\*\/
UNKNOWN_TOKEN	[^ {DELIMITER}\n]+
ARRAY          \[(({INTEGER})+((\,\s{INTEGER})+)*)?\]|\[(({FLOAT})+((\,\s{FLOAT})+)*)?\]|\[(({STRING})+((\,\s{STRING})+)*)?\]

				/* Διαχωριστής πρώτου και δεύτερου μέρους */
%%				/* Κανόνες Αναγνώρισης: {όνομα ΚΕ} {ενέργεια που εκτελείται όταν αναγνωρίζεται η αντίστοιχη λεκτική μονάδα} */

"print"		   {  prn("PRINT"); correct_words++; return PRINT;}
"scan"         {  prn("SCAN"); correct_words++; return SCAN; }
"len"          {  prn("LEN"); correct_words++; return LEN; }
"cmp"          {  prn("CMP"); correct_words++; return CMP; }
"func"         {  prn("FUNC"); correct_words++; return FUNC; }	
"if"			{  prn("IF"); correct_words++; return IF; }	
"while"        {  prn("WHILE"); correct_words++; return WHILE; }	
"for"			{  prn("FOR"); correct_words++; return FOR; }			

"(" 			{  prn("LEFT_PT"); return LEFT_PT; }
")" 		   	{  prn("RIGHT_PT"); return RIGHT_PT; }
"{" 			{  prn("LEFT_BR"); return LEFT_BR; }
"}" 		   	{  prn("RIGHT_BR"); return RIGHT_BR; }
";"            {  prn("SEMICOLON"); return SEMICOLON; }
","            {  prn("COMMA"); return COMMA; }
"="				{prn("ASSIGNOP"); return ASSIGNOP;}
"++"			{return DOUBLE_PLUS;}
"--"			{return DOUBLE_MINUS;}

{DELIMITER}		{ /* ignore whitespace */ }				/* Διαχωριστής */
{KEYWORD}		{ correct_words++; return KEYWORD; }						/* Λέξη κλειδί */
{TYPE}			{ prn("TYPE"); correct_words++; return TYPE; }
{IDENTIFIER}	{ prn("IDENTIFIER"); correct_words++; return IDENTIFIER; }					/* Αναγνωριστικά ή ονόματα */
{STRING}		 { prn("STRING"); correct_words++; return STRING; }  					/* Λεκτικά κυριολεκτικά */    
{INTEGER}		{ prn("INTEGER"); correct_words++; return INTEGER; } 					/* Ακέραιος */
{FLOAT}			{ prn("FLOAT"); correct_words++; return FLOAT; }        				/* Αριθμός κινούμενης υποδιαστολής */
{ARITH_OPERATOR}		{ prn("ARITH_OPERATOR"); return ARITH_OPERATOR; } 					/* Τελεστής */
{CMP_OPERATOR}		{ prn("CMP_OPERATOR"); return CMP_OPERATOR; } 					/* Τελεστής */
{ARRAY}        { prn("ARRAY"); correct_words++; return ARRAY; } 
{COMMENT}		{ /* ignore comments */ }				    	/* Σχόλιο */
{UNKNOWN_TOKEN} { wrong_words++; return UNKNOWN_TOKEN; }				/* Μη αναγνωρίσιμη λεκτική μονάδα */
"\n"			   { prn("NEWLINE");return NEWLINE; }								/* Ειδικός χαρακτήρας νέας γραμμής */

%%				/* Διαχωριστής δεύτερου και τρίτου μέρους */

void prn(char *s)
{
	printf("\n\t%s: %s ", s, yytext);
	return;
}