CC = gcc

CFLAGS = -Wall

DIRS = searching sorting Searches Sorts misc Conversions conversions \
      data_structures "Computer Oriented Statistical Methods"

SRC = $(wildcard *.c)

EXE = $(SRC:.c=)


.PHONY: all
all:
	@for file in $(SRC); do $(CC) $(CFLAGS) $$file -o $${file%.c}; done
	@for dir in $(DIRS); do $(MAKE) -C $$dir; done

$(DIR):
	@for dir in $(DIRS); do $(MAKE) -C $$dir; done

.PHONY: clean
clean:
	rm -f $(EXE)
	@for dir in $(DIRS); do $(MAKE) clean -C $$dir; done

