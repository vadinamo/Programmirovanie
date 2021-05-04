all: lab5 test

lab5: main.c
	gcc -pedantic -ansi -o lab5 main.c -lm

test: main.c main_test.c
	gcc -pedantic -ansi -o test -D TESTING main.c main_test.c -lm