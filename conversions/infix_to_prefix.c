#include <stdio.h>
#include <string.h>

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void infixToPrefix(char infix[], char prefix[])
{
    int length = strlen(infix);

    // Reverse the infix expression
    for (int i = 0; i < length / 2; i++)
    {
        char temp = infix[i];
        infix[i] = infix[length - i - 1];
        infix[length - i - 1] = temp;
    }

    char stack[length];
    int top = -1;
    int j = 0;

    // Scan the reversed infix expression
    for (int i = 0; i < length; i++)
    {
        if (infix[i] == ')')
            stack[++top] = infix[i];
        else if (infix[i] == '(')
        {
            while (top != -1 && stack[top] != ')') prefix[j++] = stack[top--];
            if (top != -1)
                top--;
        }
        else if (isOperator(infix[i]))
        {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                prefix[j++] = stack[top--];
            stack[++top] = infix[i];
        }
        else
        {
            prefix[j++] = infix[i];
        }
    }

    while (top != -1) prefix[j++] = stack[top--];

    // Reverse the resulting prefix expression
    for (int i = 0; i < j / 2; i++)
    {
        char temp = prefix[i];
        prefix[i] = prefix[j - i - 1];
        prefix[j - i - 1] = temp;
    }

    prefix[j] = '\0';
}

int main()
{
    char infix[] = "A+B*C";
    char prefix[20];

    printf("Infix Expression: %s\n", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix Expression: %s\n", prefix);

    return 0;
}
