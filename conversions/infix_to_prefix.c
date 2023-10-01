/**
 * @file
 * @brief [Infix to
 * Prefix](https://www.javatpoint.com/convert-infix-to-prefix-notation)
 * Expression Conversion
 * @details Convert Infixed expressions to Prefix expression.
 * @author [Rudra Narayan](https://github.com/RudraNarayan94)
 */

// include header files
#include<stdio.h>  // for printf() and scanf()
#include<string.h> // Include the header file for string manipulation
#define max 100

int top = -1, a[max]; // Initialize a stack 'a' and set 'top' to -1


/**
* @brief
* It defines a stack, a, and initializes top to -1.
* It provides functions push to push elements onto the stack and pop to pop elements from the stack.
* The prcd function returns precedence values for operators.
* The infixtoprefix function converts an infix expression to a prefix expression using a stack-based algorithm.
* In the main function, it takes user input for an infix expression, 
calls infixtoprefix to convert it to a prefix expression, 
and then prints both the input infix and the converted prefix expressions.

*/
void push(char x)
{
    a[++top] = x; // Push the character 'x' onto the stack 'a' and increment 'top'
}

char pop()
{
    if (top == -1)
        return -1; // If the stack is empty, return -1
    else
        return a[top--]; // Pop the top element from the stack 'a' and decrement 'top'
}

int prcd(char c)
{
    if (c == ')')
        return 0;     // Return 0 for closing parenthesis
    else if (c == '+' || c == '-')
        return 1;     // Return 1 for addition and subtraction operators
    else if (c == '*' || c == '/')
        return 2;     // Return 2 for multiplication and division operators
}

void infixtoprefix(char infix[max], char prefix[max])
{
    char temp, x;
    int i = 0, j = 0;

    strrev(infix); // Reverse the input infix expression (used to simplify the algorithm)

    while (infix[i] != '\0')
    {
        temp = infix[i];

        if (isalnum(temp))
        {
            prefix[j++] = temp; // If 'temp' is an alphanumeric character, add it to the prefix expression
        }
        else if (temp == ')')
        {
            push(temp); // If 'temp' is a closing parenthesis, push it onto the stack
        }
        else if (temp == '(')
        {
            while ((x = pop()) != ')')
            {
                prefix[j++] = x; // Pop and add characters from the stack to prefix until a closing parenthesis is encountered
            }
        }
        else
        {
            while (prcd(a[top]) > prcd(temp))
            {
                prefix[j++] = pop(); // Pop and add operators from the stack to prefix based on precedence
            }
            push(temp); // Push the current operator onto the stack
        }
        i++;
    }

    while (top != -1)
    {
        prefix[j++] = pop(); // Pop and add any remaining operators from the stack to prefix
    }

    prefix[j] = '\0'; // Null-terminate the prefix expression
    strrev(prefix);   // Reverse the prefix expression to get the correct order
}

int main()
{
    char infix[max], prefix[max];

    printf("Enter the infix expression:\n");
    gets(infix); // Read the infix expression from the user

    printf("The infix expression is %s\n", infix);

    infixtoprefix(infix, prefix); // Convert infix to prefix

    printf("The prefix expression is %s\n", prefix);

    return 0;
}
