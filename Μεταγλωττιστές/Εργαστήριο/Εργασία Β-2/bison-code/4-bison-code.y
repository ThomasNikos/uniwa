/* Onoma arxeiou:       simple-bison-code.y
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
		#include <math.h>
        #include <stdio.h>
		#include <stdlib.h>
        extern int yylex(void);

		extern int correct_words = 0;
		extern int wrong_words = 0;
		int correct_expressions = 0;
		int wrong_expressions = 0;
%}

/* Orismos twn anagnwrisimwn lektikwn monadwn. */
%token DELIMITER IDENTIFIER KEYWORD STRING INTEGER FLOAT OPERATOR COMMENT UNKNOWN_TOKEN NEWLINE/* FILL ME */
%token PRINT
/* Orismos proteraiothtwn sta tokens */


%%

/* Orismos twn grammatikwn kanonwn. Kathe fora pou antistoixizetai enas grammatikos
   kanonas me ta dedomena eisodou, ekteleitai o kwdikas C pou brisketai anamesa sta
   agkistra. H anamenomenh syntaksh einai:
				onoma : kanonas { kwdikas C } */
program:
        program expr NEWLINE { printf("%d\n", $2); }
        |
        ;

string:
		STRING
		| string STRING
		;

print:
		PRINT str 
		;

expr:
		print	{ correct_expressions++;}
		;
/* FILL ME */
        ;
%%

/* H synarthsh yyerror xrhsimopoieitai gia thn anafora sfalmatwn. Sygkekrimena kaleitai
   apo thn yyparse otan yparksei kapoio syntaktiko lathos. Sthn parakatw periptwsh h
   synarthsh epi ths ousias typwnei mhnyma lathous sthn othonh. */
void yyerror(char *s) {
        fprintf(stderr, "Error: %s\n", s);
}


/* H synarthsh main pou apotelei kai to shmeio ekkinhshs tou programmatos.
   Sthn sygkekrimenh periptwsh apla kalei thn synarthsh yyparse tou Bison
   gia na ksekinhsei h syntaktikh analysh. */
int main(int argc, char **argv) {
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

	/* Κλείσιμο των αρχείων που χρησιμοποιήθηκαν για την εκτέλεση του προγράμματος */
	if (yyin) fclose(yyin);
	if (yyout && yyout != stdout) fclose(yyout);
	
	return 0;
	
}