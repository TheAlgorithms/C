#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int starter(Stack *pin1, int *disks);
void finish(Stack *pin1, Stack *pin2, Stack *pin3);
int moviment(Stack *pin1, Stack *pin2, Stack *pin3);
int move(Stack *origem, Stack *destino);
void showPins(Stack *pin1, Stack *pin2, Stack *pin3);
void showPossibilities(Stack *pin1, Stack *pin2, Stack *pin3);

int main()
{

  int state = 1;
  unsigned int disks = 0;

  Stack *A = create();
  Stack *B = create();
  Stack *C = create();

  while (state != 1000)
  {
    switch (state)
    {
    case 1:
      system("cls");
      state = starter(A, &disks);
      break;
    case 2:
      system("cls");
      showPins(A, B, C);
      break;
    case 3:
      showPossibilities(A, B, C);
      break;
    case 4:
      state = moviment(A, B, C);
      break;
    case 5:
      if (length(C) == disks)
      {
        state = 6;
      }
      state = 2;
      break;
    case 6:
      finish(A, B, C);
      state = 1000;
      break;
    }
  }

  printf("game off!!");
}

int starter(Stack *pin1, int *disks)
{
  printf("\nHanoi Tower\n@leonardo-anjos\n");
  printf("How many disks do you want to play?\n");
  fflush(stdin);
  scanf("%d", disks);

  if (*disks < 0)
  {
    return 1;
  }

  int aux = *disks;
  while (aux > 0)
  {
    stackUp(pin1, aux);
    aux = aux - 1;
  }

  return 2;
}

void finish(Stack *pin1, Stack *pin2, Stack *pin3)
{
  destruir(pin1);
  destruir(pin2);
  destruir(pin3);
}

int moviment(Stack *pin1, Stack *pin2, Stack *pin3)
{
  char moviment[3] = {0, 0, '\0'};

  printf("Enter with next moviment: \n");
  fflush(stdin);
  scanf("%c%c", moviment, moviment + 1);

  switch (moviment[0])
  {
  case 'A':
    switch (moviment[1])
    {
    case 'B':
      if (move(pin1, pin2) == 0)
        return 4;
      break;
    case 'C':
      if (move(pin1, pin3) == 0)
        return 4;
      break;
    default:
      printf("Invalid moviment!\n");
      return 4;
    }
    break;
  case 'B':
    switch (moviment[1])
    {
    case 'A':
      if (move(pin2, pin1) == 0)
        return 4;
      break;
    case 'C':
      if (move(pin2, pin3) == 0)
        return 4;
      break;
    default:
      printf("Invalid moviment!\n");
      return 4;
    }
    break;
  case 'C':
    switch (moviment[1])
    {
    case 'A':
      if (move(pin3, pin1) == 0)
        return 4;
      break;
    case 'B':
      if (move(pin3, pin2) == 0)
        return 4;
      break;
    default:
      printf("Invalid moviment!\n");
      return 4;
    }
    break;
  default:
    printf("Invalid moviment!\n");
    return 4;
    break;
  }
  return 5;
}

int move(Stack *origem, Stack *destino)
{
  if (length(origem) > 0 && (length(destino) <= 0 || top(origem) < top(destino)))
  {
    stackUp(destino, unstack(origem));
    return 1;
  }
  printf("It is not possible to make this move.\n");
  return 0;
}

void showPins(Stack *pin1, Stack *pin2, Stack *pin3)
{
  printf("A: ");
  printStack(pin1);

  printf("B: ");
  printStack(pin2);

  printf("C: ");
  printStack(pin3);
}

void showPossibilities(Stack *pin1, Stack *pin2, Stack *pin3)
{
  printf("Do you can this moviments: ");

  if ((top(pin1) < top(pin2) || length(pin2) == 0) && length(pin1) > 0)
    printf(" AB ");

  if ((top(pin1) < top(pin3) || length(pin3) == 0) && length(pin1) > 0)
    printf(" AC ");

  if ((top(pin2) < top(pin1) || length(pin1) == 0) && length(pin2) > 0)
    printf(" BA ");

  if ((top(pin2) < top(pin3) || length(pin3) == 0) && length(pin2) > 0)
    printf(" BC ");

  if ((top(pin3) < top(pin1) || length(pin1) == 0) && length(pin3) > 0)
    printf(" CA ");

  if ((top(pin3) < top(pin2) || length(pin2) == 0) && length(pin3) > 0)
    printf(" CB ");

  printf("\n");
}
