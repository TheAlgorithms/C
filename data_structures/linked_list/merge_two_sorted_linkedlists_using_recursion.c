// This is the program which merges two given sorted linkedlists into a single sorted linkedlist
#include<stdio.h>
#include<stdlib.h>
// struct implementation
struct Node{
	int data;             // node data
	struct Node* next;    // address of next node
};
// function which returns the head of resultant sorted linkedlist by merging the two given sorted linkedlists 
struct Node* SortedMerge(struct Node* a, struct Node* b) {
    struct Node* result = NULL;
    if (a == NULL)  return(b);
   if (b==NULL) return(a);
   if (a->data <= b->data) {
       result = a;
       result->next = SortedMerge(a->next, b);
   }
  else{
	     result = b;
	     result->next = SortedMerge(a, b->next);
  }
   return(result);
}
// function to add an element at the front of the linked list
void push(struct Node** head_ref, int new_data){
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
// function to print the linked list
void printList(struct Node *node){
	while (node!=NULL){
		printf("%d ", node->data);
		node = node->next;
	}
}
int main()
{
	struct Node* res = NULL; // resultant linkedlist head
	struct Node* a = NULL;  // first linkedlist head
	struct Node* b = NULL;  // second linkedlist head
	// input to first linkedlist
	push(&a,120);
	push(&a, 30);
	push(&a, 20);
	push(&a, 10);
	// print first linkedlist
	printf("First Linked List is: \n");
	printList(a);
	printf("\n");
	// input to second linkedlist
	push(&b, 200);
	push(&b, 100);
	push(&b, 50);
	// print second linkedlist
	printf("Second Linked List is: \n");
	printList(b);
	printf("\n");
	// resultant merged linkedlist
	res = SortedMerge(a, b);
	// printing merged linkedlist
	printf("Merged Linked List is: \n");
	printList(res);

	return 0;
}
