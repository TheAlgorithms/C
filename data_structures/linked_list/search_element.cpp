#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
	int data;
	struct Node* link;
} Node;

typedef struct List 
{
	Node* head;
	int number_of_nodes;
} List;

int main()
{
	int choice;
	List* list = list_initialize();
	do
	{
		scanf("%d", &choice);
		switch (choice)
		{
			int element, search;
		case 1:
			/*Insert eleemnt at the End of the list*/
			scanf("%d", &element);
			insert(list, element);
			break;

		case 2:
			printf("Enter the search element:\n");
			scanf("%d", &search);
			search_ele(list, search);
			break;
		}
		
	} while (choice != 0);

	return 0;
}

List* list_initialize() 
{
	List* list = (List*)malloc(sizeof(List));
	list->head = NULL;
	list->number_of_nodes = 0;
	return list;
}

void insert(List* list, int data)
{
	Node* temp = (Node*)malloc(sizeof(Node)); Node* ptr = list->head;
	temp->link = NULL;
	temp->data = data;
	if (ptr == NULL)
	{
		list->head = temp;
	}
	else
	{
		while (ptr->link != NULL)
		{
			ptr = ptr->link;
		}
		ptr->link = temp;
	}
	list->number_of_nodes++;
}

void search_ele(List* list, int search)
{
	Node* temp = list->head;
	int success = 0;
	int pos = 1;
	while(temp!=NULL)
	{
		if (temp->data == search)
		{
			success = 1;
			break;
		}
		pos++;
		temp = temp->link;
	}
	if (success == 1)
		printf("Element found in position %d\n", pos);
	else
		printf("Element not found.\n");
}


