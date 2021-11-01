# Simple generic Stack

This is a modular generic stack data-structure. The stack is self growing.

### Content

* stack-Header file for import.
* stack.c implementation of the stack
* main.c framework program for testing.
* stack_linkedlist: Another stack implementation by linkedlist

You need to only import the **stack.h**

### Public interface

```c 
void initStack();
```

Initializes the stack with a capacity of 10 elements.

```c 
void push(void * object);
```

pushs the argument onto the stack

```c 
void  * pop();
```

pop: pops the top element of the stack from the stack.

    assumes: stack not empty.

```c 
int size();
```

gets the number of elements of the stack.

```c 
int isEmpty();
```

returns 1 if stack is empty otherwise 0.




