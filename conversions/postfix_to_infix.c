/**
 * Supported operations- '+', '-', '/', '*', '%'
 *  @author [Kavya Shah](https://github.com/Kavyashah26)
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Stack
{
    int top;
    unsigned capacity;
    char** array;
};

// createStack creates a stack with given capacity
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char**)malloc(stack->capacity * sizeof(char*));
    return stack;
}

// isEmpty checks if the stack is empty
int isEmpty(struct Stack* stack) { return stack->top == -1; }

// push pushes an element to the stack
void push(struct Stack* stack, char* item)
{
    stack->array[++stack->top] = item;
}

// pop pops an element from the stack
char* pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return NULL;
}

// isOperand checks if a character is an operand
int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

//  isOperator checks if a character is an operator
int isOperator(char ch)
{
    return ch == '+' || ch == '*' || ch == '-' || ch == '/' || ch == '^';
}

// postfixToInfix  converts postfix expression to infix
//returns correct infix operation if all the conditions are passed
char* postfixToInfix(char* postfix)
{
    struct Stack* stack = createStack(strlen(postfix));

    int operandCount = 0;
    int operatorCount = 0;

    for (int i = 0; postfix[i]; ++i)
    {
        if (isOperand(postfix[i]))
        {
            char* operand = (char*)malloc(2 * sizeof(char));
            operand[0] = postfix[i];
            operand[1] = '\0';
            push(stack, operand);
            operandCount++;
        }
        else if (isOperator(postfix[i]))
        {
            char* op2 = pop(stack);
            char* op1 = pop(stack);
            if (op1 == NULL || op2 == NULL)
            {
                assert(0 && "Invalid postfix expression. Not enough operands.");
            }
            char* temp =
                (char*)malloc((strlen(op1) + strlen(op2) + 4) * sizeof(char));
            sprintf(temp, "(%s%c%s)", op1, postfix[i], op2);
            push(stack, temp);
            operatorCount++;
        }
        else if (postfix[i] != '(' && postfix[i] != ')')
        {
            assert(0 && "Invalid character in postfix expression");
        }
    }

    if (operandCount - operatorCount != 1)
    {
        assert(0 && "Operand count and operator count do not match");
    }

    return stack->array[0];
}
static void test(){
    char* postfix[] = {
        "abc^^de-*fg^h^+i-",  
        "ab+",                 
        "ab+c*",               
    };

    char* ans[] = {
        "((((a^(b^c))*(d-e))+((f^g)^h))-i)",  
        "(a+b)",                                
        "((a+b)*c)",                           
    };
    char* result;

        for (int i = 0; i < sizeof(ans) / sizeof(ans[0]); i++){
        result=postfixToInfix(postfix[i]);
        assert(strcmp(result,ans[i])==0);
        printf("Testcase %d passed\n",i+1);
    }
    free(result); // Free memory allocated for the result
}
int main()
{
    test();
    printf("All test cases passed");
    return 0;
}
