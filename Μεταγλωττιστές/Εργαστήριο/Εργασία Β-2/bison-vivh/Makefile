all:
	bison -d 4-bison-code.y
	flex 4-bison-code.l
	gcc 4-bison-code.tab.c lex.yy.c -o 4-bison-code  -lm

clean:
	rm 4-bison-code.tab.c 4-bison-code.tab.h lex.yy.c 4-bison-code
