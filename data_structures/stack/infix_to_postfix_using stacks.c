#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the stack structure
struct stack
{
    int size;  // Size of the stack
    int top;   // Index of the top element
    char *arr; // Array to store elements
};

// Function to get the top element of the stack
char stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

// Function to check if the stack is empty
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1; // True, stack is empty
    }
    else
    {
        return 0; // False, stack is not empty
    }
}

// Function to check if the stack is full
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1; // True, stack is full
    }
    else
    {
        return 0; // False, stack is not full
    }
}

// Function to push an element onto the stack
void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

// Function to pop an element from the stack
char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// Function to determine the precedence of an operator
int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

// Function to check if a character is an operator
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}

// Function to convert infix expression to postfix
char *infixToPostfix(char *infix)
{
    // Create a stack
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    // Allocate memory for the postfix expression
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    int i = 0; // Track infix traversal
    int j = 0; // Track postfix addition

    // Process each character in the infix expression
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            // If it's not an operator, add it to the postfix expression
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            // If it's an operator, handle it based on precedence
            if (precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }

    // Pop remaining elements from the stack
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
    return postfix;
}

// Main function
int main()
{
    // Infix expression
    char *infix = "x-y/z-k*d";

    // Convert infix to postfix and print the result
    printf("Postfix is %s", infixToPostfix(infix));

    return 0;
}
