#include<stdio.h>
#include<string.h>

struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    if(!stack)
        return NULL;
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    if(!stack->array)
        return NULL;
    return stack;
}
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
void push(struct Stack* stack, char c)
{
    stack->array[++stack->top] = c;
}
char pop(struct Stack* stack)
{
    char c;
    if(!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}
char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}
int isOperand(char ch)
{
    return(ch>='A' && ch<='Z')||(ch>='a' && ch<='z');
}
int prec(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}
int infixToPostfix(char* exp)
{
    int i,k;
    struct Stack* stack = createStack(strlen(exp));
    if(!stack)
        return -1;
    for(i=0,k=-1;exp[i];++i)
    {
        if(isOperand(exp[i]))
            exp[++k] = exp[i];
        else if(exp[i] == '(')
                push(stack, exp[i]);
        else if(exp[i] == ')')
        {
            while(!isEmpty(stack) && peek(stack) != '(')
                    exp[++k] = pop(stack);
            if(!isEmpty(stack) && peek(stack) != '(')
                return -1;
            else
                pop(stack);
        }
        else
        {
            while(!isEmpty(stack) && prec(exp[i]) <= prec(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
    }
    while(!isEmpty(stack))
        exp[++k] = pop(stack );
    exp[++k] = '\0';
    printf("\nPostfix: %s", exp );
}
main(){

    char exp[100];
    printf("Enter the expression: ");
    scanf("%s", exp);
    printf("\nInfix: %s", exp);
    infixToPostfix(exp);
}
