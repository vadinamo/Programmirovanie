all: lab6 test

lab6: main.c
	gcc -pedantic -ansi -o lab6 main.c -lm

test: main.c main_test.c
	gcc -pedantic -ansi -o test -D TESTING main.c main_test.c -lm