#
# @file: Makefile
#

SRC_FILE = queue.c
SRC_TEST_FILE = queue_test.c

OBJ_FILE = queue.o
OBJ_TEST_FILE = queue_test.o
TEST_EXEC = qtest

CC = gcc
RM = rm -rf

CFLAGS = -c -Wall

all: clean lib

lib:
	$(CC) $(CFLAGS) -o $(OBJ_FILE) $(SRC_FILE)
test:
	$(CC) $(CFLAGS) -o $(OBJ_TEST_FILE) $(SRC_TEST_FILE)
	$(CC) -o $(TEST_EXEC) $(OBJ_FILE) $(OBJ_TEST_FILE)
clean:
	$(RM) $(OBJ_FILE) $(OBJ_TEST_FILE) $(TEST_EXEC)

