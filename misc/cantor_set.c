#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contour
{
	double start;
	double end;
	struct contour* next;
};
typedef struct contour Contour;
Contour *head;

void startList(double start_num, double end_num)
{
	if(head==NULL)
	{
		head = (Contour*)malloc(sizeof(Contour));
		head -> start = start_num;
		head -> end = end_num;
		head -> next = NULL;
	}
}

void propagate(Contour *head)
{
	Contour *temp = head;

	if(temp!=NULL)
	{
		Contour *newNode = (Contour*)malloc(sizeof(Contour));
		double diff = ( ((temp->end)-(temp->start)) / 3);

		newNode->end = temp->end;
		temp->end = ((temp->start)+diff);
		newNode->start = (newNode->end)-diff;

		newNode->next = temp->next;

		temp->next=newNode;

		propagate(temp->next->next);
	}
	else
		return;
}

void print(Contour *head)
{

	Contour *temp = head;
	while(temp!=NULL)
	{
		printf("\t");
		printf("[%lf] -- ", temp->start);
		printf("[%lf]", temp->end);
		temp=temp->next;
	}

	printf("\n");

}

int main(int argc, char const *argv[])
{

	head=NULL;

	int start_num, end_num, levels;

	if (argc < 2)
	{
		printf("Enter 3 arguments: start_num \t end_num \t levels\n");
		scanf("%d %d %d", &start_num, &end_num, &levels);
	}
	else
	{
		start_num = atoi(argv[1]);
		end_num = atoi(argv[2]);
		levels = atoi(argv[3]);
	}

	startList(start_num, end_num);

	for (int i = 0; i < levels; i++)
	{
		printf("Level %d\t", i);
		print(head);
		propagate(head);
		printf("\n");
	}
	printf("Level %d\t", levels);
	print(head);

	return 0;
}
