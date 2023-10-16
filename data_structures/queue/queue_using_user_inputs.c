#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
int queue[MAXSIZE];
int front = -1;
int rear = -1;
void enqueue (int data);
int dequeue ();
int peek ();
int queue_rear ();
int isfull ();
int isempty ();
int display ();
int
main ()
{
  int choice, data;
  while (1)
    {
      printf ("\nQUEUE OPERATIONS\n");
      printf ("1. Enqueue\n");
      printf ("2. Dequeue\n");
      printf ("3. Peek\n");
      printf ("4. Queue Rear\n");
      printf ("5. Isfull\n");
      printf ("6. Isempty\n");
      printf ("7. display\n");
      printf ("8. Exit\n");
      printf ("Enter your choice: ");
      scanf ("%d", &choice);
      switch (choice)
	{
	case 1:
	  printf ("Enter data to enqueue: ");
	  scanf ("%d", &data);
	  enqueue (data);
	  break;
	case 2:
	  data = dequeue ();
	  if (data != -1)
	    {
	      printf ("Dequeued element is %d\n", data);
	    }
	  break;
	case 3:
	  data = peek ();
	  if (data != -1)
	    {
	      printf ("Peeked element is %d\n", data);
	    }
	  break;
	case 4:
	  data = queue_rear ();
	  if (data != -1)
	    {
	      printf ("Queue rear is %d\n", data);
	    }
	  break;
	case 5:
	  if (isfull ())
	    {
	      printf ("Queue is full\n");
	    }
	  else
	    {
	      printf ("Queue is not full\n");
	    }
	  break;
	case 6:
	  if (isempty ())
	    {
	      printf ("Queue is empty\n");
	    }
	  else
	    {
	      printf ("Queue is not empty\n");
	    }
	  break;
	case 7:
	  if (display ())
	    {
	      printf ("Queue is empty\n");
	    }
	  else
	    {
	      printf ("Elements in queue are: \n");
	      for (int i = front; i <= rear; i++)
		{
		  printf ("%d ", queue[i]);
		}
	      printf ("\n");
	    }
	  break;
	case 8:
	  exit (0);
	default:
	  printf ("Invalid choice. Please try again.\n");
	}
    }
  return 0;
}

void
enqueue (int data)
{
  if (isfull ())
    {
      printf ("Queue is full. Cannot enqueue.\n");
      return;
    }
  if (front == -1)
    {
      front = 0;
    }
  rear++;
  queue[rear] = data;
  printf ("Enqueued element is %d\n", data);
}

int
dequeue ()
{
  if (isempty ())
    {
      printf ("Queue is empty. Cannot dequeue.\n");
      return -1;
    }
  int data = queue[front];
  front++;
  if (front > rear)
    {
      front = -1;
      rear = -1;
    }
  return data;
}

int
peek ()
{
  if (isempty ())
    {
      printf ("Queue is empty. Cannot peek.\n");
      return -1;
    }
  return queue[front];
}

int
queue_rear ()
{
  if (isempty ())
    {
      printf ("Queue is empty. Cannot get rear.\n");
      return -1;
    }
  return queue[rear];
}

int
isfull ()
{
  if (rear == MAXSIZE - 1)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

int
isempty ()
{
  if (front == -1 || front > rear)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

int
display ()
{
  if (isempty ())
    {
      printf ("Queue is empty. Cannot display.\n");
      return 1;
    }
  return 0;
}
