CC = gcc
CFLAGS = -c -Wall

all: main
main: main.o stack.o
	$(CC) main.o stack.o -o  main

stack.o: stack.c
	$(CC) $(CFLAGS) stack.c

clean:
	rm *o main
