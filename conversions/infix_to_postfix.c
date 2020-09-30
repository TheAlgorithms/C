/**
 * Program documentation
 * @name infix_to_postfix
 * @brief Infix to Postfix Expression Conversion
 * @details Convert Infixed expressions to Postfix expression.
 * @author [Harsh Karande](https://github.com/harshcut)
 */

#include <conio.h>
#include <stdio.h>

// globally declared structure
struct Stack
{
    char arr[10];  // static array of integers
    int tos;       // stores index on topmost element in stack
};

// function headers
void push(struct Stack *p, char ch);  // pust element in stack
char pop(struct Stack *p);            // pop topmost element from the stack
int isOprnd(char ch);                 // chack if element is operand or not
int isEmpty(struct Stack s);          // check if stack is empty
int prcnd(char op1, char op2);        // check operator precedence
void convert(char infix[],
             char postfix[]);  // convert infix to postfix expression

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
    char infix[20], postfix[20];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    convert(infix, postfix);
    printf("Postfix expression is %s", postfix);

    return 0;
}

/**
 * @brief push function
 * @returns void
 */
void push(struct Stack *p, char x)
{
    if (p->tos == 9)
    {
        printf("Stack Overflow!");
        return;
    }

    p->tos += 1;
    p->arr[p->tos] = x;
}

/**
 * @brief pop function
 * @returns x or \0 on exit
 */
char pop(struct Stack *p)
{
    char x;

    if (p->tos == -1)
    {
        printf("Stack Underflow!");
        return '\0';
    }

    x = p->arr[p->tos];
    p->tos -= 1;

    return x;
}

/**
 * @brief isOprnd function
 * @returns 1 or 0 on exit
 */
int isOprnd(char ch)
{
    if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) ||
        (ch >= 48 && ch <= 57))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief isEmpty function
 * @returns 1 or 0 on exit
 */
int isEmpty(struct Stack s)
{
    if (s.tos == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief convert function
 * @returns postfixed expresion or \0 on exit
 */
void convert(char infix[], char postfix[])
{
    struct Stack s;
    s.tos = -1;

    int i, j = 0, pr;
    char ch;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (isOprnd(ch) == 1)
        {
            postfix[j] = ch;
            j++;
        }
        else
        {
            while (isEmpty(s) == 0)
            {
                pr = prcnd(ch, s.arr[s.tos]);

                if (pr == 1)
                {
                    break;
                }

                postfix[j] = pop(&s);
                j++;
            }

            push(&s, ch);
        }
    }

    while (isEmpty(s) == 0)
    {
        postfix[j] = pop(&s);
        j++;
    }

    postfix[j] = '\0';
}

/**
 * @brief prcnd function
 * @returns 1 or 0 on exit
 */
int prcnd(char op1, char op2)
{
    if (op2 == '$')
    {
        return 0;
    }
    else if (op1 == '$')
    {
        return 1;
    }
    else if (op2 == '*' || op2 == '/' || op2 == '%')
    {
        return 0;
    }
    else if (op1 == '*' || op1 == '/' || op1 == '%')
    {
        return 1;
    }
    else if (op2 == '+' || op2 == '-')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
