CC = gcc
CFLAGS = -g -Wall

all: main

main: main.o dynamic_array.o
	$(CC) $(CFLAGS) $^ -o $@

dynamic_array.o: dynamic_array.c
	$(CC) $(CFLAGS) -c $^

clean: 
	rm *.o main
