#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

struct node
{
    char data;
    struct node *link;
};

int c = 0;          // c used as counter to check if stack is empty or not
struct node *head;  // declaring head pointer globally assigned to NULL

void push(char x)  // function for pushing
{
    struct node *p = head, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    if (head ==
        NULL)  // will be execute only one time i.e, 1st time push is called
    {
        head = temp;
        p = head;
        p->link = NULL;
        c++;
    }
    else
    {
        temp->link = p;
        p = temp;
        head = p;
        c++;
    }
}

char pop(void)  // function for pop
{
    char x;
    struct node *p = head;
    x = p->data;
    head = p->link;
    free(p);
    c--;
    return x;
}

int isBalanced(char *s)
{
    int i = 0;
    char x;
    while (s[i] != '\0')  // loop for covering entire string of brackets
    {
        // printf("\t s[i]=%c\n", s[i]); //DEBUG
        if (s[i] == '{' || s[i] == '(' ||
            s[i] == '[')  // if opening bracket then push
            push(s[i]);
        else
        {
            if (c <= 0)  // i.e, stack is empty as only opening brackets are
                         // added to stack
                return 0;

            x = pop();
            if (x == '{' && s[i] != '}')
                return 0;
            if (x == '[' && s[i] != ']')
                return 0;
            if (x == '(' && s[i] != ')')
                return 0;
        }
        i++;
    }

    // at end if stack is empy which means whole process has been performed
    // correctly so return 1
    return (c == 0) ? 1 : 0;
}

void destroyStack(void)
{
    struct node *p = head;
    if (c > 0)
    {
        while (p->link)
        {
            struct node *tmp = p;
            p = p->link;
            free(tmp);
        }

        c = 0;
    }
}

int main(void)
{
    int t;
    printf("\t\tBalanced parenthesis\n\n");
    printf("\nPlease enter the number of processing rounds? ");
    scanf("%d", &t);
    for (int a0 = 0; a0 < t; a0++)
    {
        char s[SIZE];
        printf("\nPlease enter the expression? ");
        scanf("%s", s);

        if (isBalanced(s))
            printf("\nYES\n");
        else
            printf("\nNO\n");

        /* tidy up stack for new round */
        destroyStack();
    }
    return 0;
}
