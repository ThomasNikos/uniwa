/* Όνομα αρχείου: 4-bison-code.l

   Περιγραφή:	Ανάπτυξη Λεκτικού Αναλυτή με τη χρήση του εργαλείου flex.
   
   Συγγραφέας:	Ομάδα Α4 - Τμήματος Α3 Εργαστηρίου Μετταγλωτιστών
   
   Σχόλια:		Το παρόν πρόγραμμα υλοποιεί, με την χρήση flex, έναν απλό λεκτικό αναλυτή που αναγνωρίζει: 
				διαχωριστές μεταξύ λέξεων, εντολών και γραμμών, λέξεις κλειδιά, τύπους μεταβλητών, αναγνωριστικά 
				ή αλλιώς ονόματα, συμβολοσειρές, αριθμούς (ακεραίους και κινούμενης υποδιαστολής), τελεστές 
				(αριθμητικούς, ανάθεσης, επαυξημένης ανάθεσης, λογικούς, συγκριτικούς, προσαύξησης και μείωσης 
				κατά ένα και διεύθυνσης μνήμης), σχόλια, απλές συναρτήσεις, συναρτήσεις χρήστη, σύνθετες δηλώσεις, 
				την εντολή επιστροφής, αγκύλες, παρενθέσεις και άγκιστρα. 
				Οτιδήποτε δεν αναγνωρίζεται ως κάτι από τα παραπάνω, επιστρέφεται ως άγνωστη λεκτική μονάδα 
				και αυξάνεται ο μετρητής προειδοποιήσεων.
				Τυπώνεται ένα μήνυμα λάθους και η γραμμή του, στην περίπτωση που δεν αναγνωριστεί κάποιο λέξημα,
				όπως και ένα προειδοποιητικό μήνυμα για χαρακτήρες που αγνοήθηκαν, μαζί με τον μετρητή τους.
*/

/* Αποφεύγεται η συγγραφή της συνάρτησης yywrap. */
%option noyywrap 	
/* Δηλώνεται η αποκλειστική αρχική κατάσταση με όνομα error. */
%x error			

/* Τμήμα ορισμών κώδικα C. 
   Οτιδήποτε μεταξύ των %{ και %} μεταφέρεται αυτούσιο στο αρχείο .c που θα δημιουργήσει το Flex. */
%{		

/* Δήλωση των header files (αρχείων επικεφαλίδας) */
#include <stdio.h>	 
#include <stdlib.h>	
#include <string.h>
/* Αρχείο το οποίο παράγεται από τον Bison κώδικα που περιέχει τις δηλώσεις μακροεντολών 
   για τα σύμβολα της γραμματικής Uni-C. */
#include "4-bison-code.tab.h"	

/* Δημιουργία μετρητών: */
int lex_warn = 0;			/* Προειδοποιήσεων και ορισμός τιμής του ως 0. */
int line = 1;				/* Τρέχουσας γραμμής και ορισμός τιμής του ως 1. */
int correct_words = 0;		/* Σωστών λέξεων και ορισμός τιμής του ως 0. */
int wrong_words = 0;		/* Λάθος λέξεων και ορισμός τιμής του ως 0. */

/* Δήλωση της συνάρτησης yyerror. */
void yyerror (const char *msg);
//void prn(char *s);

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

/* Κανόνες Αναγνώρισης που θέτουν τις ενέργειες που εκτελούνται όταν αναγνωρίζεται η αντίστοιχη λεκτική μονάδα. */
%%			/* Διαχωριστής πρώτου και δεύτερου μέρους. */	

"print"		{ correct_words++; return PRINT;}				/* Απλές συναρτήσεις ... */
"scan"		{ correct_words++; return SCAN; }
"len"		{ correct_words++; return LEN; }
"cmp"		{ correct_words++; return CMP; }				/* ... Απλές συναρτήσεις */
"func"		{ correct_words++; return FUNC; }				/* Συνάρτηση χρήστη */
"if"		{ correct_words++; return IF; }					/* Σύνθετες δηλώσεις ... */
"while"		{ correct_words++; return WHILE; }	
"for"		{ correct_words++; return FOR; }				/* ... Σύνθετες δηλώσεις */	
"return"	{ correct_words++; return RETURN; }				/* Εντολή επιστροφής */

"["			{ correct_words++; return LEFT_AR ; }			/* Αγκύλες */
"]"			{ correct_words++; return RIGHT_AR ; }	
"("			{ return LEFT_PT; }								/* Παρενθέσεις */
")"			{ return RIGHT_PT; }						
"{"			{ return LEFT_BR; }								/* Άγκιστρα */
"}"			{ return RIGHT_BR; }
"+"			{ return PLUS; }								/* Αριθμητικοί τελεστές ... */
"-"			{ return MINUS; }								
"*"			{ return TIMES; }								
"/"			{ return DIVIDE; }
"%"			{ return MOD; }
"^"			{ return POWER; }								/* ... Αριθμητικοί τελεστές */
"+="		{ return PLUS_ASSIGN; }							/* Τελεστές επαυξημένης ανάθεσης ... */
"-="		{ return MINUS_ASSIGN; }								
"*="		{ return TIMES_ASSIGN; }								
"/="		{ return DIVIDE_ASSIGN; }						/* ... Τελεστές επαυξημένης ανάθεσης */
";"			{ return SEMICOLON; }							/* Σύμβολο διαχωρισμού εντολών */
","			{ return COMMA; }								/* Κόμμα */
"="			{ return ASSIGNOP; }							/* Τελεστής ανάθεσης */
"++"		{ return DOUBLE_PLUS; }							/* Τελεστής προσαύξησης κατά ένα */
"--"		{ return DOUBLE_MINUS; }						/* Τελεστής μείωσης κατά ένα */
"!"			{ return LOG_NOT; }								/* Λογικός τελεστής NOT */
"&"			{ return '&'; }									/* Τελεστής διεύθυνσης μνήμης */
"\n"		{ line++; return NEWLINE; }						/* Σύμβολο αλλαγής γραμμής */
"\\\n"		{ line++; }										/* Σύμβολο αλλαγής φυσικών γραμμών */

{DELIMITER}			{ /* ignore whitespace */ }				/* Διαχωριστής */
{KEYWORD}			{ correct_words++; return KEYWORD; }	/* Λέξη κλειδί */						
{TYPE}				{ correct_words++; return TYPE; }		/* Τύπος μεταβλητής */
{IDENTIFIER}		{ correct_words++; return IDENTIFIER; }	/* Αναγνωριστικά ή ονόματα */
{STRING}			{ correct_words++; return STRING; }  	/* Συμβολοσειρές */		   
{INTEGER}			{ correct_words++; return INTEGER; } 	/* Ακέραιος */			
{FLOAT}				{ correct_words++; return FLOAT; }   	/* Αριθμός κινούμενης υποδιαστολής */     				
{CMP_OPERATOR}		{ return CMP_OPERATOR; } 				/* Συγκριτικός τελεστής */	
{LOGIC_OPERATOR}	{ return LOGIC_OPERATOR; }				/* Λογικός τελεστής */
{COMMENT}			{ 										/* Σχόλιο */
						char *c = yytext;
						while (*c) {
							if (*c == '\n') line++;
							c++;
						}
					}					
{UNKNOWN_TOKEN}	{ yyerror ("Unrecognized character(s) encountered!"); lex_warn++; wrong_words++; BEGIN(error); } /* Μη αναγνωρίσιμες εκφράσεις. Εκτέλεση μόνο των κανόνων που ξεκινάνε με <error>. */					  											
<error>[ \t]+	{ BEGIN(0); fprintf(yyout, "\t\t%d character(s) ignored so far\n", lex_warn); }							/* Καταστάσεις λαθών - προειδοποιήσεων... */	
<error>.		{ lex_warn++; }
<error>\n		{ BEGIN(0); line++; fprintf(yyout, "\t\t%d character(s) ignored so far\n", lex_warn); return NEWLINE; }	/* ... Καταστάσεις λαθών - προειδοποιήσεων */


%%		/* Διαχωριστής δεύτερου και τρίτου μέρους */	

/* Κώδικας συνάρτησης yyerror που τυπώνει ένα μήνυμα λάθους στην περίπτωση που αναγνωριστεί 
   λανθασμένο λέξημα και τον αριθμό γραμμής που βρίσκεται. */
void yyerror (const char *msg)
{
    fprintf(yyout, "\tLine %d at lexeme '%s' : %s\n",line, yytext, msg);	
}

/* Κώδικας συνάρτησης prn που τυπώνει στην οθόνη τον αριθμό γραμμής που βρίσκεται ο Συντακτικός Αναλυτής 
   και όποια λεκτική μονάδα αναγνωρίζει (token).
void prn(char *s)
{
    printf("\tLine: %d Flex -> Matched token: %s\n", line, yytext);
	return;
}
 */