#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
/*
This sample of code gives us hint how to add a integer to the LinkedList at any particular index using insertAt function.
*/
int main(){
    struct LinkedList *head = NULL;
    insert(&head, 900);
    insert(&head, 800);
    insert(&head, 700);
    insert(&head, 500);
    insert(&head, 400);
    insert(&head, 200);
    insertAt(&head, 0, 100);
    insertAt(&head, 2, 300);
    insertAt(&head, 1, 150);
    insertAt(&head, 20, 1000);
    insertAt(&head, 9, 950);
    insertAt(&head, 11, 1100);
    printList(head);
    return 0;
}