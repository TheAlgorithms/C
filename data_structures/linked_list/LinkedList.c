/* A single program to implement Singly, Doubly, Singly Circular and Doubly Circular Linked list.
The program expects the data to be of Integer type.
*/

#include <stdio.h>
#include <stdlib.h>

//-----------------------------------------------------------------------------------------------------------------------
// Singly Linked List

//Initialize a node
struct node {
    int data;
    struct node* next;
};

struct node* start = NULL;


//Insert at the begining of the list 
void insBeg(int val){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node ->data = val;
    new_node ->next = start;
    start = new_node;
}

//Delete a node from the beginning of the list.
void delBeg(){
    struct node* temp;
    if(start == NULL)
        printf("\nLIST IS EMPTY.");
    else{
        temp = start;
        start = start ->next;
        free(temp);
    }
}

//Insert a node at the end of the list.
void insEnd(int val) {
    struct node *temp = start;
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = val;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp -> next = new_node;
    new_node ->next = NULL;
}

//Delete a node from the end of the List.
void delEnd(){
    struct node *temp;
    temp = start;
    struct node *ptr;
    while(temp->next!=NULL){
        ptr = temp;
        temp = temp->next;
    }
    ptr ->next = NULL;
    free(temp);
}

//Insert a node after a given node in the list.
void insAfter(int val, int value){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* temp = start;
    struct node* ptr;
    new_node ->data = value;
    while(temp->data!=val){
        temp = temp ->next;
    }
    ptr = temp ->next;
    temp -> next = new_node;
    new_node->next = ptr;
}

//Delete a node after a given node in the list.
void delAfter(int val){
    struct node* temp = start;
    struct node* ptr, *prev;
    while(temp->data != val){
        temp = temp ->next;
    }
    prev = temp;
    temp = temp->next;
    ptr = temp->next;
    prev->next = ptr;
    free(temp);
}

//Insert a node before a given node in the list.
void insBefore(int val, int value){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* temp = start;
    struct node* ptr, *prev;
    new_node ->data = value;
    while (temp ->data != val){
        ptr = temp;
        temp = temp ->next;
    }
    ptr ->next = new_node;
    new_node->next = temp;
}

//Delete a node before a given node in the list.
void delBefore(int val){
    struct node* temp = start;
    struct node* ptr, *prev;
    while(temp->data!=val){
        ptr = temp;
        temp = temp ->next;
    }
    prev = ptr;
    ptr = start;
    while(ptr ->next!=temp){
        prev = ptr;
        ptr = ptr ->next;
    }
    prev ->next = temp;
    free(ptr);
}

//Display the generated list.
void display(){
    struct node* temp = start;
    while(temp != NULL){
        printf("%d", temp -> data);
        printf(" --> ");
        temp = temp -> next;
    }
}

//----------------------------------------------------------------------------------------------------------------------
//Circular
//----------------------------------------------------------------------------------------------------------------------

//Insert at the begining of the list 
void addFront(int val){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node ->data = val;
    struct node* temp = start;
    if(start == NULL){
        start = new_node;
    }
    else{
        while(temp->next!=NULL){
            temp = temp->next;
        }
        struct node* ptr = temp ->next;
        temp->next = new_node;
        new_node->next = ptr;
        start = new_node;
    }
}

//Delete a node from the beginning of the list.
void delFront(){
    struct node* temp = start;
    struct node* ptr;
    if(start == NULL) {
        printf("\nThe List is Empty");
    } else{
        while(temp->next!=start){
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = start;
        free(temp);
    }
}

//Insert a node at the end of the list.
void addEnd(int val){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = val;
    struct node* temp = start;
    while(temp->next!=start){
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

//Delete a node from the end of the list.
void deleteEnd(){
    struct node*temp = start;
    struct node* ptr;
    if(start == NULL){
        printf("\nThe List is Empty");
    } else{
        while (temp->next!=start){
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = start;
        free(temp);
    }
}

//Display the generated list
void DisplayCircular(){
    struct node* temp = start;
    if(start == NULL){
        printf("\nThe List is Empty");
    } else {
        while (temp != start) {
            printf("%d", temp->data);
            printf(" --> ");
            temp = temp->next;
        }
    }
}


//Doubly Linked List
//----------------------------------------------------------------------------------------------------------------------

//Initialize a node
struct Node{
    int Data;
    struct Node* Next;
    struct Node* Prev;
};

struct Node* head = NULL;

//Insert at the begining of the list 
void addFrontDoubly(int val){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node ->Data = val;
    new_node->Next = NULL;
    struct Node* temp;
    if(head == NULL) {
        head = new_node;
    } else{
        temp = head;
        new_node -> Next = temp;
        temp -> Prev = new_node;
        head = new_node;
        new_node->Prev = NULL;
    }
}

//Delete a node from the beginning of the list.
void delFrontDoubly(){
    struct Node* temp = head;
    struct Node* ptr;
    ptr = temp-> Next;
    ptr->Prev = NULL;
    head = ptr;
    free(temp);
}

//Insert a node at the end of the list.
void addEndDoubly(int val){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    new_node->Data = val;
    new_node->Next = NULL;
    if(head == NULL){
        head = new_node;
    } else{
        while (temp->Next!=NULL){
            temp = temp->Next;
        }
        temp->Next = new_node;
        new_node->Prev = temp;
        new_node->Next = NULL;
    }
}

//Delete a node from the end of the list.
void delEndDoubly(){
    struct Node* temp = head;
    if(head == NULL){
        printf("\nThe list is Empty");
    } else {
        while (temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Prev->Next = NULL;
        free(temp);
    }
}

//Insert a node after a given node in the list.
void addAfterDoubly(int val, int after){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    new_node->Data = val;
    while(temp ->Data!=after){
        temp = temp ->Next;
    }
    temp->Next->Prev = new_node;
    new_node ->Next = temp->Next;
    temp->Next = new_node;
    new_node->Prev = temp;
}

//Delete a node after a given node in the list.
void delAfterDoubly(int val){
    struct Node* temp = head;
    struct Node* ptr;
    if (head == NULL){
        printf("\nThe list is Empty.");
    } else{
        while (temp->Data!=val){
            temp = temp->Next;
        }
        ptr = temp->Next;
        temp ->Next = ptr->Next;
        ptr->Next->Prev = temp;
        free(ptr);
    }
}

//Insert a node before a given node in the list.
void addBefore(int val, int before){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    struct Node* ptr;
    new_node->Data = val;
    while (temp->Data!=before){
        temp = temp->Next;
    }
    ptr = temp->Prev ;
    ptr->Next = new_node;
    new_node->Next = temp;
    new_node->Prev = ptr;
    temp->Prev = new_node;
}

//Delete a node before a given node in the list.
void delBeforeDoubly(int val){
    struct Node* temp = head;
    struct Node* ptr;
    if(head == NULL){
        printf("\nThe List is Empty");
    } else{
        while (temp->Data!=val){
            temp = temp->Next;
        }
        ptr = temp->Prev->Prev;
        free(ptr->Next);
        ptr->Next = temp;
        temp ->Prev = ptr;
    }
}

//Display the generated list.
void displayDoubly(){
    struct Node* temp = head;
    if(head == NULL){
        printf("\nThe List is Empty.");
    } else{
        while (temp->Next!=NULL){
            printf("%d -->", temp->Data);
            temp = temp->Next;
        }
        printf("%d", temp->Data);
    }
}

//----------------------------------------------------------------------------------------------------------------------

//Doubly Circular Linked List
//----------------------------------------------------------------------------------------------------------------------

//Insert at the begining of the list 
void addFrontDoublyCircular(int val){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    new_node->Data = val;
    if(head == NULL){
        head = new_node;
    } else{
        while(temp->Next!=head){
            temp = temp->Next;
            }
            new_node->Next = temp->Next;
        new_node->Prev = temp;
        new_node ->Next->Prev = new_node;
        temp->Next = new_node;
        head = new_node;
    }

}

//Delete a node from the beginning of the list.
void delfrontDoublyCircular(){
    struct Node* temp = head;
    struct Node* ptr;
    if(head == NULL){
        printf("\nThe List is Empty.");
    } else{
        while (temp->Next!=head){
            temp= temp->Next;
        }
        ptr = head;
        head = head->Next;
        head ->Prev = temp;
        temp->Next = head;
        free(ptr);
    }
}

//Insert a node at the end of the list.
void addEndDoublyCircular(int val){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    new_node->Data = val;
    while (temp->Next!= head){
        temp = temp->Next;
    }
    struct Node* ptr = head;
    new_node ->Prev = temp;
    new_node ->Next = ptr;
    temp ->Next = new_node;
    ptr->Prev = new_node;
}

//Delete a node from the end of the List.
void delEndDoublyCircular(){
    struct Node* temp = head;
    if(head==NULL){
        printf("\nThe List is Empty.");
    } else{
        while (temp->Next!=head){
            temp = temp->Next;
        }
        temp->Prev->Next = head;
        head ->Prev = temp->Prev;
        free(temp);
    }
}

//Display the generated list.
void displayDoublyCircular(){
    struct Node* temp = head;
    if(head == NULL){
        printf("\nThe List is Empty");
    } else{
        while (temp->Next!=head){
            printf("%d --> ", temp->Data);
        }
        printf(" %d",temp->Data);
    }
}

//----------------------------------------------------------------------------------------------------------------------
// Switch Cases to select the desired operation


//Generate a Singly Linked List.
void SinglyLinkedList(){
    while (1) {
        int choice, value, after, before;
        printf("\n1.Insertion-Beginning\n2.Insertion-End\n3.Insertion-After a given Node.\n4.Insertion-Before a given Node.\n");
        printf("5.Deletion-Beginning\n6.Deletion-End\n7.Deletion-After a given Node.\n8.Deletion-Before a given Node.\n9.Display\n10.Exit");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nValue: ");
                scanf("%d", &value);
                insBeg(value);
                break;
            case 2:
                printf("\nValue: ");
                scanf("%d", &value);
                insEnd(value);
                break;
            case 3:
                printf("\nAfter Node with Value: ");
                scanf("%d", &after);
                printf("\nValue: ");
                scanf("%d", &value);
                insAfter(after, value);
                break;
            case 4:
                printf("\nBefore the Node with Value: ");
                scanf("%d", &before);
                printf("\nValue: ");
                scanf("%d", &value);
                insBefore(before, value);
                break;
            case 5:
                delBeg();
                break;
            case 6:
                delEnd();
                break;
            case 7:
                printf("\nDelete a node after a Node with value: ");
                scanf("%d", &after);
                delAfter(after);
                break;
            case 8:
                printf("\nDelete a node before a Node with value: ");
                scanf("%d", &before);
                delBefore(before);
                break;
            case 9:
                printf("\nThe List is: ");
                display();
                break;
            case 10:
                exit(0);
            default:
                printf("\nInvalid Input");
                break;
        }
    }
}


//Generate a Singly Circular linked list
void SinglyCircularLinkedList(){
    while (1) {
        int choice, value, after, before;
        printf("\n1.Insertion-Beginning\n2.Insertion-End\n3.Insertion-After a given Node.\n4.Insertion-Before a given Node.\n");
        printf("5.Deletion-Beginning\n6.Deletion-End\n7.Deletion-After a given Node.\n8.Deletion-Before a given Node.\n9.Display\n10.Exit");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nValue: ");
                scanf("%d", &value);
                addFront(value);
                break;
            case 2:
                printf("\nValue: ");
                scanf("%d", &value);
                addEnd(value);
                break;
            case 3:
                printf("\nAfter Node with Value: ");
                scanf("%d", &after);
                printf("\nValue: ");
                scanf("%d", &value);
                insAfter(after, value);
                break;
            case 4:
                printf("\nBefore the Node with Value: ");
                scanf("%d", &before);
                printf("\nValue: ");
                scanf("%d", &value);
                insBefore(before, value);
                break;
            case 5:
                delFront();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                printf("\nDelete a node after a Node with value: ");
                scanf("%d", &after);
                delAfter(after);
                break;
            case 8:
                printf("\nDelete a node before a Node with value: ");
                scanf("%d", &before);
                delBefore(before);
                break;
            case 9:
                printf("\nThe List is: ");
                DisplayCircular();
                break;
            case 10:
                exit(0);
            default:
                printf("\nInvalid Input.");
                break;
        }
    }
}


//Generate a Doubly Linked list
void DoublyLinkedList(){
    while (1) {
        int choice, value, after, before;
        printf("\n1.Insertion-Beginning\n2.Insertion-End\n3.Insertion-After a given Node.\n4.Insertion-Before a given Node.\n");
        printf("5.Deletion-Beginning\n6.Deletion-End\n7.Deletion-After a given Node.\n8.Deletion-Before a given Node.\n9.Display\n10.Exit");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nValue: ");
                scanf("%d", &value);
                addFrontDoubly(value);
                break;
            case 2:
                printf("\nValue: ");
                scanf("%d", &value);
                addEndDoubly(value);
                break;
            case 3:
                printf("\nAfter Node with Value: ");
                scanf("%d", &after);
                printf("\nValue: ");
                scanf("%d", &value);
                addAfterDoubly(value, after);
                break;
            case 4:
                printf("\nBefore the Node with Value: ");
                scanf("%d", &before);
                printf("\nValue: ");
                scanf("%d", &value);
                addBefore(value, before);
                break;
            case 5:
                delFrontDoubly();
                break;
            case 6:
                delEndDoubly();
                break;
            case 7:
                printf("\nDelete a node after a Node with value: ");
                scanf("%d", &after);
                delAfterDoubly(after);
                break;
            case 8:
                printf("\nDelete a node before a Node with value: ");
                scanf("%d", &before);
                delBeforeDoubly(before);
                break;
            case 9:
                printf("\nThe List is: ");
                displayDoubly();
                break;
            case 10:
                exit(0);
            default:
                printf("\nInvalid Input.");
                break;
        }
    }
}


//Generate a Doubly Circular Linked list
void DoublyCircularLinkedList(){
    while (1) {
        int choice, value, after, before;
        printf("\n1.Insertion-Beginning\n2.Insertion-End\n3.Insertion-After a given Node.\n4.Insertion-Before a given Node.\n");
        printf("5.Deletion-Beginning\n6.Deletion-End\n7.Deletion-After a given Node.\n8.Deletion-Before a given Node.\n9.Display\n10.Exit");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nValue: ");
                scanf("%d", &value);
                addFrontDoublyCircular(value);
                break;
            case 2:
                printf("\nValue: ");
                scanf("%d", &value);
                addEndDoublyCircular(value);
                break;
            case 3:
                printf("\nAfter Node with Value: ");
                scanf("%d", &after);
                printf("\nValue: ");
                scanf("%d", &value);
                addAfterDoubly(value, after);
                break;
            case 4:
                printf("\nBefore the Node with Value: ");
                scanf("%d", &before);
                printf("\nValue: ");
                scanf("%d", &value);
                addBefore(value, before);
                break;
            case 5:
                delfrontDoublyCircular();
                break;
            case 6:
                delEndDoublyCircular();
                break;
            case 7:
                printf("\nDelete a node after a Node with value: ");
                scanf("%d", &after);
                delAfterDoubly(after);
                break;
            case 8:
                printf("\nDelete a node before a Node with value: ");
                scanf("%d", &before);
                delBeforeDoubly(before);
                break;
            case 9:
                printf("\nThe List is: ");
                displayDoublyCircular();
                break;
            case 10:
                exit(0);
            default:
                printf("\nInvalid Input.");
                break;
        }
    }
}


int main(){
    int ch;
    printf("\n1.Singly Linked List\n2.Singly Circular Linked List\n3.Doubly Linked List\n4.Doubly Circular Linked List\n5.Exit");
    scanf("%d", &ch);

    //Select the type of List you wish to create
    switch (ch){
        case 1:     SinglyLinkedList();
            break;
        case 2:     SinglyCircularLinkedList();
            break;
        case 3:     DoublyLinkedList();
            break;
        case 4:     DoublyCircularLinkedList();
            break;
        case 5: exit(0);
        default:    printf("INVALID INPUT");
            break;
    }
    return 0;
}
