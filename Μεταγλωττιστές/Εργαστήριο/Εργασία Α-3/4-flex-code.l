/* Όνομα αρχείου: 4-flex-code.l

   Περιγραφή:	Ανάπτυξη Λεκτικού Αναλυτή με τη χρήση του εργαλείου flex.
   
   Συγγραφέας:	Ομάδα Α4 - Τμήματος Α3 Εργαστηρίου Μετταγλωτιστών
   
   Σχόλεια:		Το παρόν πρόγραμμα υλοποιεί, με την χρήση flex, έναν απλό λεκτικό αναλυτή που 
				αναγνωρίζει διαχωριστές μεταξύ λέξεων (delimiters), λέξεις κλειδιά (keywords), 
				αναγνωριστικά ή αλλιώς ονόματα (identifiers), λεκτικά κυριολεκτικά (strings), 
				ακέραιους αριθμούς (integers), αριθμούς κινούμενης υποδιαστολής (float), 
				τελεστές (operators), σχόλια (comments) για τη γλώσσα Uni-C, ενώ διαχειρίζεται 
				τους ειδικούς χαρακτήρες νέας γραμμής '\n' (new line) και 'EOF' (end of line). 
				Ότιδήποτε δεν αναγνωρίζεται ως κάτι από τα παραπάνω, επιστρέφεται ως άγνωστη
				λεκτική μονάδα (unknown token). 
				Ο Λεκτικός Αναλυτής δέχεται ορίσματα αρχείων για είσοδο και έξοδο. 
				
   Οδηγείες εκτέλεσεις:	Εισαγωγή της λέξης make στον τρέχον κατάλογο ή
						flex -o 4-flex-code.c 4-flex-code.l
                        gcc -o 4-flex-code 4-flex-code.c 
                        ./4-flex-code input output
*/

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
#include "token.h"	

int line = 1;	/* Δημιουργία μετρητή τρέχουσας γραμμής και ορισμός τιμής του ως 1 */

%}

/* Ορισμοί ονομάτων Κανονικών Εκφράσεων (ΚΕ): Αριστερά όνομα - Δεξιά ΚΕ */
DELIMITER		[ \t;]+
IDENTIFIER		[a-zA-Z]+((_+)*([0-9]+)*([a-zA-Z]+)*)*|_+((_+)*([0-9]+)*([a-zA-Z]+)*)*
KEYWORD			break|case|func|const|continue|double|do|else|float|for|if|int|long|return|short|sizeof|struct|switch|void|while
STRING			\"(([^\"\n\\])*(\\\")*(\\n)*(\\\\)*)*\"
INTEGER			[1-9]([0-9]+)?|0[xX][a-fA-F0-9]+|0[0-7]*
FLOAT			[0-9]+[eE]-?[0-9]+(\.[0-9]+)?|[0-9]+\.[0-9]+([eE]-?[0-9]+(\.[0-9]+)?)?
OPERATOR		\+=|\+=|-=|\*=|\/=|\+\+|--|&&|\|\||\*|\+=|==|!=|<=|>=|\+|-|\/|%|=|!|<|>|&
COMMENT			\/\/.*\n|\/\*(.*\n*)*?\*\/
UNKNOWN_TOKEN	[^ {DELIM}\n]+

				/* Διαχωριστής πρώτου και δεύτερου μέρους */
%%				/* Κανόνες Αναγνώρισης: {όνομα ΚΕ} {ενέργεια που εκτελείται όταν αναγνωρίζεται η αντίστοιχη λεκτική μονάδα} */

{DELIMITER}		{ /* ignore whitespace */ }				/* Διαχωριστής */
{KEYWORD}		{ return KEYWORD; }						/* Λέξη κλειδί */
{IDENTIFIER}	{ return IDENTIFIER; }					/* Αναγνωριστικά ή ονόματα */
{STRING}		{ return STRING; }  					/* Λεκτικά κυριολεκτικά */    
{INTEGER}		{ return INTEGER; } 					/* Ακέραιος */
{FLOAT}			{ return FLOAT; }        				/* Αριθμός κινούμενης υποδιαστολής */
{OPERATOR}		{ return OPERATOR; } 					/* Τελεστής */
{COMMENT}		{ /* ignore comments */ }				    	/* Σχόλιο */
{UNKNOWN_TOKEN} { return UNKNOWN_TOKEN; }				/* Μη αναγνωρίσιμη λεκτική μονάδα */
\n				{ line++; }								/* Ειδικός χαρακτήρας νέας γραμμής */
<<EOF>>			{ printf("#END-OF-FILE#\n"); exit(0); }	/* Ειδικός χαρακτήρας End Of File */

%%				/* Διαχωριστής δεύτερου και τρίτου μέρους */

/* Πίνακας με όλες τις λεκτικές μονάδες αντίστοιχα με τους ορισμούς στο αρχείο token.h */
char *tname[9] = {"DELIMITER","IDENTIFIER","KEYWORD","STRING","INTEGER","FLOAT","OPERATOR","COMMENT","UNKNOWN_TOKEN"};
 
/* Η συνάρτηση main μεταφέρεται αυτούσια στο αρχείο .c που θα δημιουργήσει το Flex. 
   Εκτελείται πρώτη στην εφαρμογή του λεκτικού αναλυτή. */
int main(int argc, char **argv) {

	int token; 

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
	} else {
		fprintf(stderr, "Usage: %s input (output)\n", *argv);
		return 2;
	}

	/* Για κάθε token που αναγνωρίζεται εκτυπώνεται η γραμμή που βρέθηκε, το όνομά του και η τιμή του. */
	while( (token = yylex()) >= 0) {
			fprintf(yyout, "\tLine = %d, token = %s, value = \"%s\"\n", line, tname[token-1], yytext);
		}

	/* Κλείσιμο των αρχείων που χρησιμοποιήθηκαν για την εκτέλεση του προγράμματος */
	if (yyin) fclose(yyin);
	if (yyout && yyout != stdout) fclose(yyout);
	
	return 0;
	
}