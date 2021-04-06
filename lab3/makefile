all: lab3 test

lab3: main.c
	gcc -pedantic -ansi -o lab3 main.c -lm

test: main.c main_test.c
	gcc -pedantic -ansi -o test -D TESTING main.c main_test.c -lm