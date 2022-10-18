/*
This header file contains all the basic funations and some useful functions that are performed on Singly LinkedList. 
The Node struct is replaced by LinkedList (just to feel better while creating ;()).
*/
struct LinkedList {
    int data;
    struct LinkedList *next;
};

void printList(struct LinkedList* );
/*
The above printList function prints the complete list with a decoration (-> show arrow to the next node). It takes the head node as parameter
*/
void insert(struct LinkedList** , int );
/*
The above function inserts the given integer type data to the head of the LinkedList. It takes the address of the head node pointer as first parameter and integer to be added in the LinkedList as second parameter.
*/
void insertAt(struct LinkedList** , int , int );
/*
The above function allow us to add an integer to any particular index in the LinkedList. It take three parameters first is the address of the head node pointer, second is the index where to add the data and the third is the integer value that is to be added in the LinkedList.
NOTE-> if the given index is out of bound than the integer will be added to the last of the LinkedList.
*/
struct LinkedList* LinkedList(int[] , int );
/*
LinkedList() function is a utility function that takes in an array of integers and length of the array as parameters and returns a LinkedList of having all the nodes as given in the array. In simple words , it use an array to create an LinkedList of identical data in it as the array.
We can assign this function to the head node directly and the head node with be connected to the LinkedList created in the function.
*/
void append(struct LinkedList** , int );
/*
This funtion inserts the iteger value to the last of the LinkedList.
*/
int delete(struct LinkedList** );
/*
delete() function deletes the head node and assign the next of head as new head pointer. Simultaneously it frees the allocated memory space of the deleted node.
*/
int deleteThis(struct LinkedList** , int );
/*
This is a utility function that find the given integer value in the LinkedList and deletes the first occurance from the LinkedList of that number.
*/
int deleteOn(struct LinkedList** , int );
/*
This functions simply deletes the node present at the index given to the function as a parameter.
*/
void pop(struct LinkedList** );
/*
This pop functions deletes the node from the last of the LinkedList and returns it so that we can use it for our processing.
*/
void printList(struct LinkedList *head){
    while(head!=NULL){
        printf("%d ->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void insert(struct LinkedList **head, int data){
    struct LinkedList *new;
    new = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    new->data = data;
    new->next = (*head);
    (*head) = new;
}

void insertAt(struct LinkedList **head, int index, int data){
    if(index==0){
        insert(head, data);
        return;
    }
    struct LinkedList *new;
    new = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    new->data = data;
    struct LinkedList *ptr = *head;
    while(ptr!=NULL&&index>1&&ptr->next!=NULL){
        index--;
        ptr =  ptr->next;
    }
    new->next = ptr->next;
    ptr->next = new;
}

struct LinkedList* LinkedList(int arr[], int size){
    struct LinkedList *newHead = NULL;
    for(int i=size-1;i>=0;--i){
        insert(&newHead, arr[i]);
    }
    return newHead;
}

void append(struct LinkedList **head, int data){
    if((*head)==NULL){
        insert(head, data);
        return;
    }
    struct LinkedList *new;
    new = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    new->data = data;
    struct LinkedList *ptr = *head;
    while(ptr!=NULL&&ptr->next!=NULL){
        ptr =  ptr->next;
    }
    new->next = ptr->next;
    ptr->next = new;
}

int delete(struct LinkedList **head){
    if((*head)==NULL){
        return -1;
    }
    int data = (*head)->data;
    struct LinkedList *ptr = (*head);
    (*head) = (*head)->next;
    free(ptr);
    return data;
}

int deleteThis(struct LinkedList **head, int data){
    struct LinkedList *ptr = (*head);
    if(ptr==NULL){
        return -1;
    }
    if(ptr->data==data){
        return delete(head);
    }
    struct LinkedList *prevptr = (*head);
    while(ptr!=NULL&&ptr->next!=NULL){
        ptr = ptr->next;
        if(ptr->data==data){
            break;
        }
        prevptr = prevptr->next;
    }
    prevptr->next = prevptr->next->next;
    int dt = ptr->data;
    free(ptr);
    return dt;
}

int deleteOn(struct LinkedList **head, int index){
    if(index==0){
        return delete(head);
    }
    struct LinkedList *ptr = (*head);
    struct LinkedList *prevptr = (*head);
    int pos = index;
    int i=0;
    while(ptr!=NULL&&ptr->next!=NULL){
        pos--;
        i++;
        ptr = ptr->next;
        if(pos==0){
            break;
        }
        prevptr = prevptr->next;
    }
    if(i<index){
        return -1;
    }
    int data = ptr->data;
    prevptr->next = ptr->next;
    free(ptr);
    return data;
}

void pop(struct LinkedList **head){
    struct LinkedList *ptr = (*head);
    struct LinkedList *prevptr = (*head);
    while(ptr!=NULL){
        ptr = ptr->next;
        if(ptr->next==NULL){
            break;
        }
        prevptr = prevptr->next;
    }
    prevptr->next = NULL;
    free(ptr);
}