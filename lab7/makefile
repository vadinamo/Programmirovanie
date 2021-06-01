main:
	gcc -o main departmentList.c main.c
test:
	gcc -coverage -o test functionTest.c test.c -lm

runtest:
	./test

clear:
	del  functionTest.c.gcov, functionTest.gcda, functionTest.gcno test.gcda test.gcno

checkcov:
	gcov functionTest