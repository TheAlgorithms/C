#include <stdio.h>
#include <string.h>

// Define a stack structure to hold characters
struct Stack {
    char arr[10];
    int tos; // Top of stack
};

// Function to push a character onto the stack
void push(struct Stack *p, char ch) {
    // Check for stack overflow
    if (p->tos == 9) {
        printf("Stack Overflow!");
        return;
    }

    p->tos += 1; // Increment top of stack
    p->arr[p->tos] = ch; // Store character in the stack
}

// Function to pop a character from the stack
char pop(struct Stack *p) {
    char x;

    // Check for stack underflow
    if (p->tos == -1) {
        printf("Stack Underflow!");
        return '\0';
    }

    x = p->arr[p->tos]; // Get character from the top of the stack
    p->tos -= 1; // Decrement top of stack

    return x;
}

// Function to check if a character is an operand
int isOperand(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

// Function to check if the stack is empty
int isEmpty(struct Stack s) {
    return s.tos == -1;
}

// Function to determine operator precedence
int getPrecedence(char op1, char op2) {
    if ((op1 == '*' || op1 == '/' || op1 == '%') && (op2 == '+' || op2 == '-')) {
        return 1;
    }
    return 0;
}

// Function to convert infix expression to prefix expression
void infixToPrefix(char infix[], char prefix[]) {
    struct Stack s; // Initialize a stack
    s.tos = -1; // Initialize top of stack

    int i, j = 0;
    char ch, temp;
    int len = strlen(infix);

    // Scan the infix expression from right to left
    for (i = len - 1; i >= 0; i--) {
        ch = infix[i];

        if (isOperand(ch)) {
            prefix[j] = ch; // Add operand to prefix expression
            j++;
        } else {
            if (ch == ')') {
                push(&s, ch); // Push ')' onto the stack
            } else if (ch == '(') {
                while ((temp = pop(&s)) != ')') {
                    prefix[j] = temp; // Pop and add operators to prefix until '(' is encountered
                    j++;
                }
            } else {
                while (!isEmpty(s) && getPrecedence(ch, s.arr[s.tos])) {
                    temp = pop(&s);
                    prefix[j] = temp; // Pop and add operators to prefix based on precedence
                    j++;
                }
                push(&s, ch); // Push the current operator onto the stack
            }
        }
    }

    // Pop any remaining operators from the stack and add to prefix
    while (!isEmpty(s)) {
        temp = pop(&s);
        prefix[j] = temp;
        j++;
    }

    prefix[j] = '\0';

    // Reverse the prefix expression to get the correct order
    strrev(prefix);
}



int main() {
    char infix[20], prefix[20];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression is %s\n", prefix);

    return 0;
}
