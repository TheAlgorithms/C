#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
/*
Finding an element in the List and than deleting it usinf deleteThis function.
*/
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    struct LinkedList *head = LinkedList(arr, 7);
    printList(head);
    deleteThis(&head, 1);
    printList(head);
    deleteThis(&head, 4);
    printList(head);
    deleteThis(&head, 7);
    printList(head);
    return 0;
}