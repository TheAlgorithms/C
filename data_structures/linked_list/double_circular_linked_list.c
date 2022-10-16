//Everything about Double Circular Linked list.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next, *prev;
} LL;

LL* input(LL *);
void display(LL *, LL *);
LL* insertFirst(LL *, LL *);
LL* insertLast(LL *, LL*);
void insertPos(LL*);
LL* delFirst(LL *, LL *);
LL* delLast(LL *, LL *);
void delPos(LL *);
void menu(LL *Head);

int main(){
    LL *Head, *new;
    new = (LL *) malloc(sizeof(LL));
    Head = NULL;

    printf("Enter first element into linked list: ");
    scanf("%d", &new->data);
    Head = new;
    new -> next = Head;
    new -> prev = Head;

    menu(Head);
    return 0;
}

void menu(LL *Head){
    int userInput, flag = 1;
    LL *Tail;
    char ch;
    do{
        printf("\nEnter 1 to input data\n");
        printf("Enter 2 to display data\n");
        printf("Enter 3 to insert element at beginnning\n");
        printf("Enter 4 to insert element at end\n");
        printf("Enter 5 to insert element at positon:\n");
        printf("Enter 6 to delete first element\n");
        printf("Enter 7 to delete last element\n");
        printf("Enter 8 to delete element from position\n");

        printf("Enter any other integer to exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &userInput);

        switch(userInput){
            case 1:
                Tail = input(Head);
                break;
            case 2:
                display(Head, Tail);
                break;
            case 3:
                Head = insertFirst(Head, Tail);
                display(Head, Tail);
                break;
            case 4:
                Tail = insertLast(Head, Tail);
                display(Head, Tail);
                break;
            case 5:
                insertPos(Head);
                display(Head, Tail);
                break;
            case 6:
                Head = delFirst(Head, Tail);
                display(Head, Tail);
                break;
            case 7:
                Tail = delLast(Head, Tail);
                display(Head, Tail);
                break;
            case 8:
                delPos(Head);
                display(Head, Tail);
                break;
            default:
                flag = 0;
                break;
        }

    } while (flag);
    display(Head, Tail);
}

LL* input(LL *Head){
    LL *ptr, *new, *Tail;
    char ch;
    ptr = Head;
    do{
        new = (LL *) malloc(sizeof(LL));
        new -> prev = ptr;
        ptr -> next = new;
        new -> next = Head;

        printf("Enter elements into linked list: ");
        scanf("%d", &new->data);
        ptr = ptr->next;

        printf("Do you want to continue (Y/N): ");
        getchar();
        ch = getchar();
    }while ((ch == 'y') || (ch == 'Y'));

    Tail = ptr;
    return Tail;
}

void display(LL *Head, LL* Tail){
    LL *ptr = Head;
    printf("\nData: ");
    do{
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }while (ptr != Head);
    printf("%d\n", ptr->data);

    ptr = Tail;
    printf("Reversed Data: ");
    printf("%d ", Head -> data);
    while (ptr != Head){
        printf("%d ", ptr -> data);
        ptr = ptr -> prev;
    }
    printf("%d\n", ptr->data);
}

LL* insertFirst(LL *head, LL* Tail){
    LL *new = (LL *) malloc(sizeof(LL));
    new -> next = head;
    new -> prev = Tail;
    head -> prev = new;
    head = new;
    Tail -> next = head;
    printf("Enter data to be inserted: ");
    scanf("%d", &new->data);
    return head;
}

LL* insertLast(LL* Head, LL *Tail){
    LL *new, *ptr;
    ptr = Tail;
    new = (LL *) malloc(sizeof(LL));
    ptr -> next = new;
    new -> prev = ptr;
    new -> next = Head;
    Tail = new;

    printf("Enter data to be inserted: ");
    scanf("%d", &new->data);
    return Tail;
}

void insertPos(LL *Head){
    LL *new, *ptr;
    int pos, count = 0;
    new = (LL *) malloc(sizeof(LL));
    ptr = Head;
    printf("Enter position at which element is to be inserted: ");
    scanf("%d", &pos);
    printf("Enter element to be inserted: ");
    scanf("%d", &new->data);
    do{
        ptr = ptr->next;
        count++;
    }while((ptr != Head) && (count<pos-2));

    new -> next = ptr -> next;
    ptr -> next = new;
    new -> prev = ptr;
    new -> next -> prev = new;
}

LL* delFirst(LL *Head, LL *Tail){
    LL *temp;
    temp = Head;
    Head = Head -> next;
    Tail -> next = Head;
    Head -> prev = Tail;
    free(temp);
    return Head;
}

LL* delLast(LL *Head, LL *Tail){
    LL *temp, *ptr;
    ptr = Tail;
    temp = ptr;
    ptr -> prev -> next = Head;
    Tail = ptr -> prev;
    free(temp);
    return Tail;
}

void delPos(LL *Head){
    LL *temp, *ptr;
    int pos, count = 0;
    ptr = Head;
    printf("Enter position at which element is to be deleted: ");
    scanf("%d", &pos);
    do{
        ptr = ptr->next;
        count++;
    }while((ptr->next != Head) && (count < pos-2));
    
    temp = ptr->next;
    ptr->next = (ptr->next)->next;
    ptr -> next -> prev = ptr;
    free(temp);
}
