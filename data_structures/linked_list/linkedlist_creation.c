#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
/*
In this code, first we create the nodes of LinkedList by allocating memory to each of it and than manually connects each other.
*/
int main(){
    struct LinkedList *head, *second, *third;
    head = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    second = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    third = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;
    printList(head);
    return 0;
}