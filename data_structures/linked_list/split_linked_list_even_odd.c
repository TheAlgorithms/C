/*
Split the given linked list of integral numbers into linked list of even and odd integers. 
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* nxt;
} Node;


void initialisation (Node**);
void insertion_serial_order (Node **, int);
void split_and_display (Node *, Node**, Node **);
void display(Node*);

// Function to initialize a node with NULL
void initialisation (Node **aa_head){
	
	*aa_head=NULL;
}

// Function to insert an element to the linked list.
void insertion_serial_order (Node**aa_head, int n){
	
	Node* t, *prv, *cur;
	t=(Node *) malloc (sizeof(Node*));
	t->data=n; 
	for(cur =*aa_head, prv=NULL; cur ; cur=cur->nxt){
		prv=cur;
	}
		
	t->nxt=cur;
	if (prv!=NULL){
		prv->nxt=t;
	}
	else{
		*aa_head=t;
	}
	
}

//  Function for splitting the linked list.
void split (Node *a_head, Node **aa_head_odd, Node**aa_head_even){
	
	Node* cur;
	initialisation (aa_head_even);
	initialisation (aa_head_odd);
	 
	for (cur = a_head; cur; cur=cur->nxt){
		
		if(cur->data%2==0){
			insertion_serial_order (aa_head_even, cur->data);
		}
		else{
			insertion_serial_order (aa_head_odd, cur->data);
		}
	}
	
}

// Display the linked list
void display (Node *a_head){
	Node* temp;
	temp=a_head;
	while(temp){
		printf("%d ",temp->data);
		temp = temp->nxt;
	}
	printf("\n");
}

// Main Function
void main(){	
	Node *head = NULL;
	Node *even = NULL;
	Node *odd = NULL;
	initialisation(&head);
	
	int item=0;
	int choice=0;
	
	do{
		printf("Enter your choice: ");
		printf("\n1.INSERT Element\n2.SPLIT and Display\n3.Display list\n4.EXIT\n");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				printf("Enter the item to insert in the list: ");
				scanf("%d",&item);
				insertion_serial_order(&head,item);
				printf("Current list items: ");
				display(head);
				break;
				
			case 2:
				split (head, &odd, &even);
				printf("\nThe linked list with even integers are: ");
				display(even);
				printf("The linked list with odd integers are: ");
				display(odd);
				break;
			case 3:
				printf("\nCurrent list items: ");
				display(head);
				break;
			case 4:
				exit(1);
				break;
			default:
				printf("\nEnter appropriate choice (1,2,3 or 4)\n");
		}
	}while(choice!=4);

}
	
	
/* OUTPUT CONSOLE

Enter your choice:
1.INSERT Element
2.SPLIT and Display
3.Display list
4.EXIT
1
Enter the item to insert in the list: 74
Current list items: 74

Enter your choice:
1.INSERT Element
2.SPLIT and Display
3.Display list
4.EXIT
1
Enter the item to insert in the list: 85
Current list items: 74 85

Enter your choice:
1.INSERT Element
2.SPLIT and Display
3.Display list
4.EXIT
1
Enter the item to insert in the list: 10
Current list items: 74 85 10

Enter your choice:
1.INSERT Element
2.SPLIT and Display
3.Display list
4.EXIT
2
The linked list with even integers are: 74 10
The linked list with odd integers are: 85

*/	
	
	
