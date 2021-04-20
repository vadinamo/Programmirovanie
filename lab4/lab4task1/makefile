all: lab4task1 test

lab4task1: main.c
	gcc -pedantic -ansi -o lab4task1 main.c -lm

test: main.c main_test.c
	gcc -pedantic -ansi -o test -D TESTING main.c main_test.c -lm