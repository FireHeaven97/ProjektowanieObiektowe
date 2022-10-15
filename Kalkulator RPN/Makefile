CC = gcc

all:  main.o stack.o	
	$(CC) main.o stack.o -o stack

allagain: clear all

main.o: main.c stack.h
	$(CC) -c main.c -o main.o

stack.o: stack.c stack.h
	$(CC) -c stack.c -o stack.o
clear:
	rm -f *~
	rm -f *.o
	rm -f stack
