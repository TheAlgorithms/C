CC = gcc
CFLAGS = -g -Wall

all: main

main: main.o hash_set.o
	$(CC) $(CFLAGS) $^ -o $@

hash_set.o: hash_set.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm *.o main