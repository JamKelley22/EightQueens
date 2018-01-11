all: queens

queens: queens.o
	@gcc -Wall -o queens queens.o

clean: 
	@rm -f queens.o
	@rm -f queens
