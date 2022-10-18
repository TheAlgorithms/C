#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
/*
This sample of code shows how to delete a node on a particular index from a LinkedList using deleteOn function.
*/
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    struct LinkedList *head = LinkedList(arr, 5);
    printList(head);
    deleteOn(&head, 4);
    printList(head);
    deleteOn(&head, 3);
    printList(head);
    deleteOn(&head, 2);
    printList(head);
    deleteOn(&head, 1);
    printList(head);
    deleteOn(&head, 0);
    printList(head);
    return 0;
}