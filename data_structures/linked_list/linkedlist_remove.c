#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
/*
delete function deletes the head node from the LinkedList and sets the next of the head node as new head. Here is the implementation.
*/
int main(){
    struct LinkedList *head = NULL;
    insert(&head, 500);
    insert(&head, 400);
    insert(&head, 300);
    insert(&head, 200);
    insert(&head, 100);
    insert(&head, 50);
    printList(head);
    printf("The deleted node is %d\n", delete(&head));
    printList(head);
    printf("The deleted node is %d\n", delete(&head));
    printf("The deleted node is %d\n", delete(&head));
    printList(head);
    printf("The deleted node is %d\n", delete(&head));
    printList(head);
    printf("The deleted node is %d\n", delete(&head));
    printList(head);
    printf("The deleted node is %d\n", delete(&head));
    printList(head);
    printf("The deleted node is %d\n", delete(&head));
    return 0;
}