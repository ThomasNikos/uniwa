%option noyywrap
%{
	#include <stdio.h>
	int num_lines = 0, num_chars = 0;
%}

%%

\n	{num_lines++; num_chars++;}
.	{num_chars++;}

%%

	int main()
	{
		yylex();
		printf("# of lines = %d\n", num_lines);
		printf("# of chars = %d\n", num_chars);		
	}