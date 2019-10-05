#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct Stack
{
    int top;
    unsigned capacity;
    int* array;
    /* data */
};
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    if(!stack)
     return NULL;
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(sizeof(int));
    if(!stack->array)
        return NULL;
    return stack;
}
char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}
void push(struct Stack* stack, char val)
{
    stack->array[++stack->top] = val;
}
int isEmpty(struct Stack* stack)
{
    if(stack->top==-1)
    return 1;
    else
    return 0;
}
char pop(struct Stack* stack)
{
    if(!isEmpty(stack))
    return stack->array[stack->top--];
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
int isOperand(char ch)
{
    return(ch>='0' && ch<='9');
}
int infxiToPostfix(char* exp)
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
int evaluatePostfix(char* exp)
{
    int i,val1,val2,ans;
    struct Stack* stack = createStack(strlen(exp));
    if(!stack)
    return -1;
    for(i=0;exp[i];i++)
    {
        if(isOperand(exp[i]))
            push(stack, exp[i]-'0');
        else
        {
            val1 = pop(stack);
            val2 = pop(stack);
            switch (exp[i])
            {
                case '+': push(stack, val1+val2); break;
                case '-': push(stack, val1-val2); break;
                case '*': push(stack, val1*val2); break;
                case '/': push(stack, val1/val2); break;
                case '^': push(stack, pow(val2, val1)); break;
            }
        }
    }
    return pop(stack);
}

int main()
{
    char exp[100];
    printf("\nEnter the expresssion: ");
    scanf("%s", exp);
    printf("\nInfix: %s", exp);
  infxiToPostfix(exp);
    printf("\nAns: %d", evaluatePostfix(exp));
    /* code */
    return 0;
}
