            // C program for array implementation of stack 
#include <limits.h>                 
#include <stdio.h> 
#include <stdlib.h> 
  
// A structure to represent a stack 
        struct Stack { 
                int up; 
             unsigned total; 
             int* arr; 
                }; 
  
// function to create a stack of given capacity. It initializes size of 

// stack as 0 

    struct Stack* createStack(unsigned total) 
{ 
     struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
     
        stack->total = total; 
        
     stack->up = -1; 
     
     stack->arr = (int*)malloc(stack->total * sizeof(int)); 
     
        return stack; 
} 
  
    // Stack is full when top is equal to the last index 
    
    int isFull(struct Stack* stack) 
{ 
        return stack->up == stack->total - 1; 
} 
  
// Stack is empty when top is equal to -1 

    int isEmpty(struct Stack* stack) 
{ 
    return stack->up == -1; 
} 
  
// Function to add an item to stack.  It increases top by 1 
        void push(struct Stack* stack, int item) 
{ 
         if (isFull(stack)) 
               return; 
                stack->arr[++stack->up] = item; 
             printf("%d pushed to stack\n", item); 
} 
  
// Function to remove an item from stack.  It decreases top by 1 
        int pop(struct Stack* stack) 
{ 
         if (isEmpty(stack)) 
              return INT_MIN; 
         return stack->arr[stack->up--]; 
} 
  
// Function to return the top from stack without removing it    
    int peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->arr[stack->up]; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    struct Stack* stack = createStack(100); 
  
    push(stack, 101); 
    push(stack, 2); 
    push(stack, 96); 
  
    printf("%d popped from stack\n", pop(stack)); 
  
    return 0; 
} 

