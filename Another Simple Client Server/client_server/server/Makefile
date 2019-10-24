all: compile clean
compile: 
	gcc -Wall -pthread server.c -o server
clean: 
	-@rm -rf *.o 2>/dev/null || true
