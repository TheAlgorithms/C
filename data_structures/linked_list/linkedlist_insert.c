#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
/*
This example shows insertion in a LinkedList using insert function.
*/
int main(){
    struct LinkedList *head = NULL;
    insert(&head, 200);
    insert(&head, 300);
    insert(&head, 500);
    insert(&head, 600);
    printList(head);
    return 0;
}