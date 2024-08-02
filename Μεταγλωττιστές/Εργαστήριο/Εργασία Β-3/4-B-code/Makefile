all:
	bison -d 4-bison-code.y
	flex 4-bison-code.l
	gcc 4-bison-code.tab.c lex.yy.c -o 4-bison-code  -lm
	@echo
	@echo ----------Successful run----------
	@#4-bison-code input_success.txt output_success.txt
	./4-bison-code input_success.txt output_success.txt
	@echo ----------Failed run--------------
	@#4-bison-code input_fail.txt output_fail.txt
	./4-bison-code input_fail.txt output_fail.txt
clean:
	rm 4-bison-code.tab.c 4-bison-code.tab.h lex.yy.c 4-bison-code
