CC = gcc

CFLAGS = -Wall

SRC = $(wildcard *.c)

EXE = $(SRC:.c=)

.PHONY: all
all: 
	@for file in $(SRC); do $(CC) $(CFLAGS) $$file -o $${file%.c}; done

.PHONY: clean
clean:
	rm -f $(EXE)
