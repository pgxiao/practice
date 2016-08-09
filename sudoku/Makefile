#
# Makefile
#
# Computer Science 50
# Problem Set 3
#

all: sudoku

sudoku: sudoku.c helpers.c helpers.h
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o sudoku sudoku.c helpers.c -lm

clean:
	rm -f *.o a.out core sudoku