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
        #include <stdio.h>
	#include <stdlib.h>
        int yylex(void);
        void yyerror(char *);
%}

/* Orismos twn anagnwrisimwn lektikwn monadwn. */
%token INTCONST VARIABLE PLUS NEWLINE /* FILL ME */

/* Orismos proteraiothtwn sta tokens */
%left PLUS

%%

/* Orismos twn grammatikwn kanonwn. Kathe fora pou antistoixizetai enas grammatikos
   kanonas me ta dedomena eisodou, ekteleitai o kwdikas C pou brisketai anamesa sta
   agkistra. H anamenomenh syntaksh einai:
				onoma : kanonas { kwdikas C } */
program:
        program expr NEWLINE { printf("%d\n", $2); }
        |
        ;
expr:
        INTCONST         { $$ = $1; }
	| VARIABLE	 { $$ = $1; }
        | expr PLUS expr { $$ = $1 + $3; }
/* FILL ME */
        ;
%%

/* H synarthsh yylex ylopoiei enan autonomo lektiko analyth. Edw anagnwrizontai
   oi lektikes monades ths glwssas Uni-C */
int yylex() {
	char buf[100];
	char num = 0;
	int zero = 0;
        char c;

	// Diabase enan xarakthra apo thn eisodo
        c = getchar();

        // Ean o xarakthras einai keno h tab, agnohse ton kai diabase ton epomeno
        while (c == ' ' || c == '\t') { yylval = 0; c = getchar(); }

	// An brethei enas xarakthras A-Z, a-z h _ tote prokeitai gia metablhth
	if ((c >= 'A' && c <= 'Z') ||
	    (c >= 'a' && c <= 'z') ||
	    (c == '_'))
	{
		sprintf(buf, "%c", c);
		c = getchar();
		// O epomenos xarakthras meta ton prwto mporei na einai kai pshfio 0-9
		while((c >= 'A' && c <= 'Z') ||
		      (c >= 'a' && c <= 'z') ||
		      (c >= '0' && c <= '9') ||
		      (c == '_'))
		{
			sprintf(buf, "%s%c", buf, c);
			c = getchar();
		}
		ungetc(c, stdin);
		yylval = 0;
		printf("\tScanner returned: VARIABLE (%s)\n", buf);
		return VARIABLE;
	}

        // Gia kathe xarakthra pou einai arithmos ginetai h topothethsh tou sthn yylval
        while (c >= '0' && c <= '9')
        {
		if (zero > 0) { zero = 0; yyerror("integer starting with zero"); exit(1); }
		if (c == '0') zero++;
		if (num == 0) yylval = 0;
                yylval = (yylval * 10) + (c - '0');
		num = 1;
		c = getchar();
        }
        if (num)
	{
		ungetc(c, stdin);
		printf("\tScanner returned: INTCONST (%d)\n", yylval);
		return INTCONST;
	}

	// Ean o xarakthras einai to symbolo + prokeitai gia prosthesh
        if (c == '+')
	{
		printf("\tScanner returned: PLUS (%c)\n", c);
		return PLUS;
	}

	// Ean prokeitai gia ton eidiko xarakthra neas grammhs
        if (c == '\n')
	{
		yylval = 0;
		printf("\tScanner returned: NEWLINE (\\n)\n");
		return NEWLINE;
	}

	// Ean prokeitai gia ton eidiko xarakthra telous arxeiou
	if (c == EOF)
	{
		printf("\tScanner returned: EOF (EOF)\n");
		exit(0);
	}

	/* FILL ME */

	// Gia otidhpote allo kalese thn yyerror me mhnyma lathous
	yyerror("invalid character");
}


/* H synarthsh yyerror xrhsimopoieitai gia thn anafora sfalmatwn. Sygkekrimena kaleitai
   apo thn yyparse otan yparksei kapoio syntaktiko lathos. Sthn parakatw periptwsh h
   synarthsh epi ths ousias typwnei mhnyma lathous sthn othonh. */
void yyerror(char *s) {
        fprintf(stderr, "Error: %s\n", s);
}


/* H synarthsh main pou apotelei kai to shmeio ekkinhshs tou programmatos.
   Sthn sygkekrimenh periptwsh apla kalei thn synarthsh yyparse tou Bison
   gia na ksekinhsei h syntaktikh analysh. */
int main(void)  {
        yyparse();
        return 0;
}
