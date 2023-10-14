/*
    A C program to multiply 2 polynomials using Linked-List Data Structures
    The code takes 2 polynomials as input and prints the product of them as output
    @author [Abdul Kadir](https://github.com/AK3847)
*/
#include <stdio.h>
#include <stdlib.h>

struct Node //structure for the Linked-List
{
    int cf; //coefficient
    int pow; //power
    struct Node *next;
} *head1, *head2, *ans; //declaring 3 Linked-Lists

struct Node *addNode(struct Node *start, int cfx, int powx);// function to add new node to Linked-List

struct Node *multiplypolynomial(struct Node *head1, struct Node *head2, struct Node *ans); //function to multiply given 2 Linked-List

void display(struct Node *x); //function to display a linked-list

struct Node *addsamevariables(struct Node *head);// function to check if user gave two different variables with same power and handle it

struct Node *addNode(struct Node *start, int cfx, int powx)
{
    struct Node *p;
    struct Node *temp = malloc(sizeof(struct Node));
    temp->cf = cfx;
    temp->pow = powx;
    temp->next = NULL;
    if (start == NULL || powx > start->pow)
    {
        temp->next = start;
        start = temp;
    }
    else
    {
        p = start;
        while (p->next != NULL && p->next->pow >= powx) p = p->next;
        temp->next = p->next;
        p->next = temp;
    }
    return start;
}
struct Node *multiplypolynomial(struct Node *head1, struct Node *head2,struct Node *ans)
{
    struct Node *p1 = head1;
    struct Node *p2 = head2;
    int final_cf, final_pow;
    while (p1 != NULL)
    {
        while (p2 != NULL)
        {
            final_cf = (p1->cf) * (p2->cf);
            final_pow = (p1->pow) + (p2->pow);
            ans = addNode(ans, final_cf, final_pow);
            p2 = p2->next;
        }
        p2 = head2;
        p1 = p1->next;
    }
    ans = addsamevariables(ans);
    return ans;
}
struct Node *addsamevariables(struct Node *head)
{
    struct Node *p3, *temp;
    p3 = head;
    while (p3->next != NULL)
    {
        if (p3->pow == p3->next->pow)
        {
            p3->cf = p3->cf + p3->next->cf;
            temp = p3->next;
            p3->next = p3->next->next;
            free(temp);
        }
        else
            p3 = p3->next;
    }
    return head;
}
void display(struct Node *x)
{
    struct Node *p = x;
    if (x == NULL)
        printf("NO POLYNOMIAL\n");
    else
    {
        while (p != NULL)
        {
            if (p->cf == 1)
                printf("");
            printf("(%.1d*x^%d)", p->cf, p->pow);
            p = p->next;
            if (p != NULL)
                printf("+");
            else
                printf("\n");
        }
    }
}

int main() //main function
{
    int cf = 1, pw = 1;
    int n;
    printf("For your 1st polynomial give the number of terms:\n");
    scanf("%d", &n);
    while (n--)
    {
        printf("Please give your terms-coeffcient and power:\n");
        scanf("%d %d", &cf, &pw);
        if (cf != -99 && pw != -99)
            head1 = addNode(head1, cf, pw);
    }
    cf = 1, pw = 1;
    printf("For your 2nd polynomial give the number of terms:\n");
    scanf("%d", &n);
    while (n--)
    {
        printf("Please give your terms-coeffcient and power:\n");
        scanf("%d %d", &cf, &pw);
        if (cf != -99 && pw != -99)
            head2 = addNode(head2, cf, pw);
    }
    printf("Your 1st polynomial:\n");
    head1 = addsamevariables(head1);

    display(head1); //printing the first polynomial
    printf("\n");

    printf("Your 2nd polynomial:\n");
    head2 = addsamevariables(head2);

    display(head2); //printing the second polynomial
    printf("\n");

    ans = multiplypolynomial(head1, head2, ans); //storing the answer in "ans" linked-list

    printf("Multiplication of given 2 polynomials is:\n");
    display(ans); //printing the final answer

    return 0;
}
