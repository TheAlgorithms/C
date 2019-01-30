# Define the machine object files for your program
OBJECTS = compare.o BinarySearchTree.o AVLTree.o
# Define your include file
INCLUDES = BinarySearchTree.h AVLTree.h

# make for the executable
run.exe: ${OBJECTS}
	gcc -g -o run.exe ${OBJECTS}

# Simple suffix rules for the .o
%.o: %.c ${INCLUDES}
	gcc -g -c -O3 $<

# Clean the .o files
clean:
	rm -f ${OBJECTS}

