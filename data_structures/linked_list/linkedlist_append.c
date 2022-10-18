#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
/*
This sample of code shows you how to append a value to the LinkedList created in the main function.
*/
int main(){
    struct LinkedList *head = NULL;
    append(&head, 300);
    append(&head, 400);
    insert(&head, 250);
    append(&head, 600);
    printList(head);
    return 0;
}