#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>


struct Node{
	int data;
	uintptr_t both;
};typedef struct Node node;


void add(node **head, int data){
	node *new_node = (node*)malloc(sizeof(node));
	new_node->data = data;
  if(*head == NULL){
        new_node->both = (uintptr_t)NULL ^ (uintptr_t)NULL;
        *head = new_node;
    }
		else{
        uintptr_t iter = (uintptr_t)NULL, pre = (uintptr_t)NULL;
        node *temp = *head;
        while(temp){
            pre = (uintptr_t)temp;
            iter ^= (uintptr_t)temp->both;
            temp = (void *)iter;
            iter = pre;
        }
        temp = (void *)pre;
        uintptr_t swap = (uintptr_t)temp->both ^ (uintptr_t)NULL;
        temp->both = (uintptr_t)swap ^ (uintptr_t)new_node;
        new_node->both = (uintptr_t)NULL ^ (uintptr_t)temp;
			}
}

void printList(node *head){
    uintptr_t iter = (uintptr_t)NULL, swap;
    while(head){
        printf("%d ", head->data);
        iter ^= (uintptr_t)(head->both);
        swap = (uintptr_t)head;
        head = (void *)iter;
        iter = swap;
    }
		printf("\n");
}

node *get(node *head, int index){
    if(!head || index < 0) return NULL;
    uintptr_t iter = (uintptr_t)NULL, swap;
    int i = 0;
    while(head){
        if(index == i++) return head;
        iter ^= (uintptr_t)head->both;
        swap = (uintptr_t)head;
        head = (void *)iter;
        iter = swap;
    }
    return NULL;

}

int main(){
    node *head = NULL;
    add(&head, 5);
    add(&head, 6);
    add(&head, 1);
    add(&head, 67);
    add(&head, 63);
    printList(head); // Output : 5 6 1 67 63
    printf("%d\n", get(head, 3)->data); // Output : 67
    printf("%d\n", get(head, 5)->data); // Output : segmentation fault
    return 0;
}
