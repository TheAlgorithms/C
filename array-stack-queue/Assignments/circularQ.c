#include<stdio.h>
#include<stdlib.h>
#define SIZE 5         
int CQ[SIZE], f = -1, r = -1; 
int CQfull(),CQempty();
 
int CQinsert(int elem) { 
 if (CQfull())
  printf("\n\n Overflow!!!!\n\n");
 else {
  if (f == -1)
   f = 0;
  r = (r + 1) % SIZE;
  CQ[r] = elem;
 }
}
 
int CQdelete() { 
 int elem;
 if (CQempty()) {
  printf("\n\nUnderflow!!!!\n\n");
  return (-1);
 } else {
  elem = CQ[f];
  if (f == r) {
   f = -1;
   r = -1;
  } 
  else
   f = (f + 1) % SIZE;
  return (elem);
 }
}
 
int CQfull() { 
 if ((f == r + 1) || (f == 0 && r == SIZE - 1))
  return 1;
 return 0;
}
 
int CQempty() { 
 if (f == -1)
  return 1;
 return 0;
}
 
void display() { 
 int i;
 if (CQempty())
  printf(" \n Empty Queue\n");
 else {
  printf("Front[%d]->", f);
  for (i = f; i != r; i = (i + 1) % SIZE)
   printf("%d ", CQ[i]);
  printf("%d ", CQ[i]);
  printf("<-[%d]Rear\n\n", r);
 }
}
 
int main() 
{ 
 int opn, elem;
 while(1)
	{
	  printf("\n\n---> Circular Queue Operations <---\n");
	  printf("\n Press 1-Insert, 2-Delete,3-Display,4-Exit\n");
	  printf("\n Your option: ");
	  scanf("%d", &opn);
	  switch(opn) 
		{
		  case 1: printf("\nEnter the element to be Inserted: ");
   			  scanf("%d", &elem);
   			  CQinsert(elem);
   			  break;
  		  case 2: elem = CQdelete();
   			  if (elem != -1)
    			  printf("\n\nDeleted Element is %d \n\n", elem);
   			  break;
  		  case 3: printf("\n\nStatus of Circular Queue\n\n");
   		          display();
   			  break;
 		  case 4: exit(0);
  			  default:
  			  printf("\n\nInvalid Option !!! Try Again !! \n\n");
   			  break;
 
		}
	}
}

