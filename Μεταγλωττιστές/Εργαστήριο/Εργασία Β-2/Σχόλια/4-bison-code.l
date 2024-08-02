/* Όνομα αρχείου: 4-bison-code.l

   Περιγραφή:	Ανάπτυξη Λεκτικού Αναλυτή με τη χρήση του εργαλείου flex.
   
   Συγγραφέας:	Ομάδα Α4 - Τμήματος Α3 Εργαστηρίου Μετταγλωτιστών
   
   Σχόλια:		Το παρόν πρόγραμμα υλοποιεί, με την χρήση flex, έναν απλό λεκτικό αναλυτή που αναγνωρίζει: 
				διαχωριστές μεταξύ λέξεων, εντολών και γραμμών, λέξεις κλειδιά, τύπους μεταβλητών, αναγνωριστικά 
				ή αλλιώς ονόματα, λεκτικά κυριολεκτικά, αριθμούς (ακεραίους και κινούμενης υποδιαστολής), τελεστές 
				(αριθμητικούς, ανάθεσης, επαυξημένης ανάθεσης, λογικούς, συγκριτικούς, προσαύξησης και μείωσης 
				κατά ένα και διεύθυνσης μνήμης), σχόλια, απλές συναρτήσεις, συναρτήσεις χρήστη, σύνθετες δηλώσεις, 
				την εντολή επιστροφής, αγκύλες, παρενθέσεις και άγκιστρα. 
				Ότιδήποτε δεν αναγνωρίζεται ως κάτι από τα παραπάνω, επιστρέφεται ως άγνωστη λεκτική μονάδα 
				και αυξάνεται ο μετρητής προειδοποιήσεων.
				Τυπώνεται στην οθόνη η τρέχουσα γραμμή, η λεκτική μονάδα που αναγνωρίζεται και ένα μήνυμα λάθους 
				στην περίπτωση που δεν αναγνωριστεί.

*/

/* Αποφεύγεται η συγγραφή της συνάρτησης yywrap. */
%option noyywrap 	
/* Δηλώνεται η αποκλειστική αρχική κατάσταση με όνομα error */
%x error			

/* Τμήμα ορισμών κώδικα C. 
   Οτιδήποτε μεταξύ των %{ και %} μεταφέρεται αυτούσιο στο αρχείο .c που θα δημιουργήσει το Flex. */
%{		

/* Δήλωση των header files (αρχείων επικεφαλίδας) */
#include <stdio.h>	 
#include <stdlib.h>	
#include <string.h>
/* Αρχείο (4-bison-code.tab.h) το οποίο παράγεται από τον Bison κώδικα με το %defines που περιέχει 
   τις δηλώσεις μακροεντολών για τα σύμβολα της γραμματικής Uni-C. */
#include "4-bison-code.tab.h"	

int lex_warn = 0;	/* Δημιουργία μετρητή προειδοποιήσεων και ορισμός τιμής του ως 0 */

int line=1;			/* Δημιουργία μετρητή τρέχουσας γραμμής και ορισμός τιμής του ως 1 */

/* Δήλωση των συναρτήσεων yyerror και prn */
void yyerror (const char *msg);
void prn(char *s);

int correct_words = 0;		/* Δημιουργία μετρητή σωστών λέξεων και ορισμός τιμής του ως 0 */
int wrong_words = 0;		/* Δημιουργία μετρητή λάθος λέξεων και ορισμός τιμής του ως 0 */

%}

/* Ορισμοί ονομάτων Κανονικών Εκφράσεων (ΚΕ). */
DELIMITER		([ \t]+) 
IDENTIFIER		[a-zA-Z]+((_+)*([0-9]+)*([a-zA-Z]+)*)*|_+((_+)*([0-9]+)*([a-zA-Z]+)*)*
KEYWORD			break|case|func|const|continue|do|else|long|return|sizeof|struct|switch|void
TYPE            double|int|long|short|float
STRING			\"(([^\"\n\\])*(\\\")*(\\n)*(\\\\)*)*\" 
INTEGER			[1-9]([0-9]+)?|0[xX][a-fA-F0-9]+|0[0-7]*
FLOAT			[0-9]+[eE]-?[0-9]+(\.[0-9]+)?|[0-9]+\.[0-9]+([eE]-?[0-9]+(\.[0-9]+)?)?
CMP_OPERATOR	">"|"<"|"<="|">="|"=="|"!="
LOGIC_OPERATOR	"&&"|"||"
COMMENT			\/\/.*\n|\/\*(.*\n*)*?\*\/
UNKNOWN_TOKEN	.

/* Κανόνες Αναγνώρισης που θέτουν τις ενέργειες που εκτελούνται όταν αναγνωρίζεται η αντίστοιχη έφραση. */
%%			/* Διαχωριστής πρώτου και δεύτερου μέρους. */	

"print"		{ prn("PRINT"); correct_words++; return PRINT;}				/* Απλές συναρτήσεις ... */
"scan"		{ prn("SCAN"); correct_words++; return SCAN; }
"len"		{ prn("LEN"); correct_words++; return LEN; }
"cmp"		{ prn("CMP"); correct_words++; return CMP; }				/* ... Απλές συναρτήσεις */
"func"		{ prn("FUNC"); correct_words++; return FUNC; }				/* Συνάρτηση χρήστη */
"if"		{ prn("IF"); correct_words++; return IF; }					/* Σύνθετες δηλώσεις ... */
"while"		{ prn("WHILE"); correct_words++; return WHILE; }	
"for"		{ prn("FOR"); correct_words++; return FOR; }				/* ... Σύνθετες δηλώσεις */	
"return"	{ prn ("RETURN"); correct_words++; return RETURN; }			/* Εντολή επιστροφής */

"["			{ prn ("LEFT_AR"); correct_words++; return LEFT_AR ; }		/* Αγκύλες */
"]"			{ prn ("RIGHT_AR"); correct_words++; return RIGHT_AR ; }	
"("			{ prn("LEFT_PT"); return LEFT_PT; }							/* Παρενθέσεις */
")"			{ prn("RIGHT_PT"); return RIGHT_PT; }						
"{"			{ prn("LEFT_BR"); return LEFT_BR; }							/* Άγκιστρα */
"}"			{ prn("RIGHT_BR"); return RIGHT_BR; }
"+"			{ prn("PLUS"); return PLUS; }								/* Αριθμητικοί τελεστές ... */
"-"			{ prn("MINUS"); return MINUS; }								
"*"			{ prn("TIMES"); return TIMES; }								
"/"			{ prn("DIVIDE"); return DIVIDE; }
"%"			{ prn("MOD"); return MOD; }
"^"			{ prn("POWER"); return POWER; }								/* ... Αριθμητικοί τελεστές */
"+="		{ prn("PLUS_ASSIGN"); return PLUS_ASSIGN; }					/* Τελεστές επαυξημένης ανάθεσης ... */
"-="		{ prn("MINUS_ASSIGN"); return MINUS_ASSIGN; }								
"*="		{ prn("TIMES_ASSIGN"); return TIMES_ASSIGN; }								
"/="		{ prn("DIVIDE_ASSIGN"); return DIVIDE_ASSIGN; }				/* ... Τελεστές επαυξημένης ανάθεσης */
";"			{ prn("SEMICOLON"); return SEMICOLON; }						/* Σύμβολο διαχωρισμού εντολών */
","			{ prn("COMMA"); return COMMA; }								/* Κόμμα */
"="			{ prn("ASSIGNOP"); return ASSIGNOP; }						/* Τελεστής ανάθεσης */
"++"		{ prn("DOUBLE_PLUS"); return DOUBLE_PLUS; }										/* Τελεστής προσαύξησης κατά ένα */
"--"		{ prn("DOUBLE_MINUS"); return DOUBLE_MINUS; }									/* Τελεστής μείωσης κατά ένα */
"!"			{ prn ("LOGIC_OPERATOR"); return LOG_NOT; }					/* Λογικός τελεστής NOT */
"&"			{ prn("AMPERSAND"); return '&'; }							/* Τελεστής διεύθυνσης μνήμης */
"\n"		{ prn("NEWLINE"); line++; return NEWLINE; }					/* Σύμβολο αλλαγής γραμμής */
"\\\n"		{ line++; }													/* Σύμβολο αλλαγής φυσικών γραμμών */

{DELIMITER}			{ /* ignore whitespace */ }									/* Διαχωριστής */
{KEYWORD}			{ correct_words++; return KEYWORD; }						/* Λέξη κλειδί */						
{TYPE}				{ prn("TYPE"); correct_words++; return TYPE; }				/* Τύπος μεταβλητής */
{IDENTIFIER}		{ prn("IDENTIFIER"); correct_words++; return IDENTIFIER; }	/* Αναγνωριστικά ή ονόματα */
{STRING}			{ prn("STRING"); correct_words++; return STRING; }  		/* Λεκτικά κυριολεκτικά */		   
{INTEGER}			{ prn("INTEGER"); correct_words++; return INTEGER; } 		/* Ακέραιος */			
{FLOAT}				{ prn("FLOAT"); correct_words++; return FLOAT; }   			/* Αριθμός κινούμενης υποδιαστολής */     				
{CMP_OPERATOR}		{ prn("CMP_OPERATOR"); return CMP_OPERATOR; } 				/* Συγκριτικός τελεστής */	
{LOGIC_OPERATOR}	{ prn ("LOGIC_OPERATOR"); return LOGIC_OPERATOR; }			/* Λογικός τελεστής */
{COMMENT}			{ 															/* Σχόλιο */
						char *c = yytext;
						while (*c) {
							if (*c == '\n') line++;
							c++;
						}
					}	
										
{UNKNOWN_TOKEN}	{ yyerror ("Unrecognized character(s) encountered!"); lex_warn++; wrong_words++; BEGIN(error); } /* Μη αναγνωρίσιμες εκφράσεις. Εκτέλεση μόνο των κανόνων που ξεκινάνε με <error>. */					  											
<error>[ \t]+	{ BEGIN(0); printf("\t\t%d character(s) ignored so far\n", lex_warn); }							/* Καταστάσεις λαθών - προειδοποιήσεων... */	
<error>.		{ lex_warn++; }
<error>\n		{ BEGIN(0); line++; printf("\t\t%d character(s) ignored so far\n", lex_warn); return NEWLINE; }	/* ... Καταστάσεις λαθών - προειδοποιήσεων */


%%		/* Διαχωριστής δεύτερου και τρίτου μέρους */	

/* Κώδικας συνάρτησης yyerror που τυπώνει στην οθόνη ένα μήνυμα λάθους στην περίπτωση που αναγνωριστεί 
   λανθασμένη λεκτική μονάδα (token) και τον αριθμό γραμμής που βρίσκεται. */
void yyerror (const char *msg)
{
    fprintf(yyout, "\tLine %d at lexeme \'%s\' : %s\n",line, yytext, msg);		//??
}

/* Κώδικας συνάρτησης prn που τυπώνει στην οθόνη τον αριθμό γραμμής που βρίσκεται ο Συντακτικός Αναλυτής 
   και όποια λεκτική μονάδα αναγνωρίζει (token). */
void prn(char *s)
{
    printf("\tLine: %d Flex -> Matched token: %s\n", line, yytext);
	return;
}