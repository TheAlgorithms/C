HEADERS = ../*.h  ../*/*.h ../*/*/*.h
OBJECTS = ./main.o ./bloom_filter.o

CC=gcc 
CFLAGS= -Wall -Wextra -g

.PHONY: clean all default run debug bloom

default: test

%.o: %.c $(HEADERS)
	$(CC) -c $< -o $@ $(CFLAGS)

test: $(OBJECTS)
	$(CC) $(OBJECTS) -o ./bin/$@.exe $(CFLAGS)

run: test
	./bin/test.exe

debug: test
	lldb ./bin/test.exe

clean:
	-rm -f $(OBJECTS)
	-rm -f ./bin/test.exe