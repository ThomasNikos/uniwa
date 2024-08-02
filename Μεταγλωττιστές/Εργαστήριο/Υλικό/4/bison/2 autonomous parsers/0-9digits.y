/*  ������ BISON  �� ����� digit.y (����� Flex) ��� ���� ����������� ��� ���������� ����� ��� newline (digit.y). ��� ��������� ���� ������ syntax error.  */

%{
        #include <stdio.h>
        int yylex(void);
        void yyerror(char *);
		#define YYDEBUG 1; //2 (0-9digits.output)
%}

%token DIGIT NEWLINE

%%

program:
        program expr NEWLINE { printf("Digit: %d\n", $2); }
        |
        ;
expr:
        DIGIT          { $$ = $1; }
        ;
%%

yylex() {
        char c;
        c = getchar();

        // Process all digits
        if (c >= '0' && c <= '9')
        {
                yylval = c - '0';
                return DIGIT;
        }
        if (c == '\n') return NEWLINE;
		if(c == EOF) return 0; //1 (^z)
        yyerror("invalid character");
}

void yyerror(char *s) {
        fprintf(stderr, "%s\n", s);
}

int main(void)  {
		yydebug=1; //2 (0-9digits.output)
        yyparse();
        return 0;
}