#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
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
void push(struct Node** head_ref, int new_data){
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
void printList(struct Node *node){
	while (node!=NULL){
		printf("%d ", node->data);
		node = node->next;
	}
}
int main()
{
	struct Node* res = NULL;
	struct Node* a = NULL;
	struct Node* b = NULL;
	push(&a,120);
	push(&a, 30);
	push(&a, 20);
	push(&a, 10);
	printf("First Linked List is: \n");
	printList(a);
	printf("\n");
	push(&b, 200);
	push(&b, 100);
	push(&b, 50);
	printf("Second Linked List is: \n");
	printList(b);
	printf("\n");
	res = SortedMerge(a, b);
	printf("Merged Linked List is: \n");
	printList(res);

	return 0;
}
