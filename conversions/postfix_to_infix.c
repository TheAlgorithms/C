#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a stack of strings
struct Stack {
    char *arr[100]; // Array to store strings
    int top;        // Top of the stack
};

// Function to push a string onto the stack
void push(struct Stack *s, char *item) {
    s->top++;
    s->arr[s->top] = strdup(item); // Duplicate and store the string
}

// Function to pop a string from the stack
char *pop(struct Stack *s) {
    if (s->top < 0) {
        return NULL; // Stack underflow
    }
    return s->arr[s->top--];
}

// Function to check if a character is an operator (+, -, *, /)
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert a postfix expression to infix
char *postfixToInfix(char *postfix) {
    struct Stack stack;
    stack.top = -1;

    int len = strlen(postfix);
    char *operand1, *operand2, *result, *temp;

    for (int i = 0; i < len; i++) {
        char token[2] = {postfix[i], '\0'};

        if (!isOperator(token[0])) {
            push(&stack, token);
        } else {
            operand2 = pop(&stack);
            operand1 = pop(&stack);
            if (operand1 == NULL || operand2 == NULL) {
                printf("Invalid postfix expression.\n");
                return NULL;
            }

            // Combine operands and operator to create a subexpression
            result = (char *)malloc(strlen(operand1) + strlen(operand2) + 4);
            sprintf(result, "(%s%s%s)", operand1, token, operand2);

            // Push the subexpression back onto the stack
            push(&stack, result);

            // Free the memory used by operands
            free(operand1);
            free(operand2);
        }
    }

    char *infix = pop(&stack);
    if (stack.top != -1) {
        printf("Invalid postfix expression.\n");
        return NULL;
    }

    return infix;
}

int main() {
    char postfix[100];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    char *infix = postfixToInfix(postfix);
    if (infix != NULL) {
        printf("Infix expression is: %s\n", infix);
        free(infix); // Free the dynamically allocated memory
    }

    return 0;
}
