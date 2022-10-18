#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
/*
Implementation of pop function on LinkedList.
*/
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    struct LinkedList *head = LinkedList(arr, 8);
    printList(head);
    pop(&head);
    printList(head);
    return 0;
}