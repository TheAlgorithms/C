#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

#define TAM_MAX 10

struct stack
{
  int items[TAM_MAX];
  int top;
};

Stack *create()
{
  Stack *p = malloc(sizeof(Stack));
  p->top = 0;
  return p;
}

void destroy(Stack *p)
{
  if (p != NULL)
  {
    free(p);
  }
}

void stackUp(Stack *p, int valor)
{
  if (p->top == TAM_MAX)
  {
    printf("Stackoverflow!\n");
    return;
  }
  p->items[p->top++] = valor;
}

int unstack(Stack *p)
{
  if (p->top == 0)
  {
    printf("Stack empty!\n");
    return -1;
  }
  return p->items[--p->top];
}

int length(Stack *p)
{
  return p->top;
}

int top(Stack *p)
{
  if (p->top == 0)
  {
    printf("Stack empty!\n");
    return -1;
  }
  return p->items[p->top - 1];
}

void printStack(Stack *p)
{
  int i;
  printf("[ ");
  for (i = 0; i < p->top; i++)
  {
    printf("%d ", p->items[i]);
  }
  printf("]\n");
}

void reverse3(Stack *p)
{
  int i, f, tmp;
  for (i = 0, f = p->top - 1; i < f; i++, f--)
  {
    tmp = p->items[i];
    p->items[i] = p->items[f];
    p->items[f] = tmp;
  }
}
