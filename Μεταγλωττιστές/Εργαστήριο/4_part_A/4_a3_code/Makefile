all:
	flex -o 4-flex-code.c 4-flex-code.l
	gcc -o 4-flex-code 4-flex-code.c 
	./4-flex-code input.txt output.txt
clean:
	rm 4-flex-code 4-flex-code.c
