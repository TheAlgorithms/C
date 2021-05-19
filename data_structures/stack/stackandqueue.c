#include<stdio.h>
#include<stdlib.h>
 

typedef struct Node node;
struct Node{
    int value;
    struct Node * next;
};



struct Node * Q1_Head;
struct Node * Q1_tail;

struct Node * Q2_Head;
struct Node * Q2_tail;

// node*top;


node* new_node(int x) {
    node* t = (node*) malloc(sizeof(node));

    t -> value = x;
    t -> next = NULL;

    return t;
}

 
void enqueue(int val, node**head, node**tail){
    node*temp;
    if (*head == NULL)
    {
        // printf("%d",val);
        temp = new_node(val);
        (*head) = temp;
        (*tail) = temp;
    }
    else{
        temp = new_node(val);
        (*tail) -> next = temp;
        *tail = (*tail)->next;
    }
}

node* dequeue(node**head, node**tail){
    if(*head == NULL){
        return NULL;
    }
    struct Node * temp;
    temp = *head;
    *head = (*head)->next;
    if(*head == NULL){
        *tail  = NULL;
    }
    return temp;
}

void push(int x){
    enqueue(x,&Q2_Head,&Q2_tail);
    // printf("%d    ",Q2_Head->value);
    node*temp = dequeue(&Q1_Head, &Q1_tail);
    while(temp != NULL){
        enqueue(temp->value,&Q2_Head,&Q2_tail);
        temp = dequeue(&Q1_Head, &Q1_tail);
    }
    temp = Q1_Head;
    Q1_Head = Q2_Head;
    Q2_Head = temp;

    temp = Q1_tail;
    Q1_tail = Q2_tail;
    Q2_tail = temp;
    // printf("%d    ",Q1_Head->value);
}

void pop(){
    node*temp = dequeue(&Q1_Head, &Q1_tail);
}

void disp(){
    node*last = Q1_Head;
    if(last == NULL){
        printf("Empty\n"); return;
    }
    while(last!=NULL){
        printf("%d ",last->value);
        last = last -> next;
    }
    printf("\n");
}

int main(){
    Q1_Head = NULL;
    Q1_tail = NULL;
    Q2_Head = NULL;
    Q2_tail = NULL;
    // top = NULL;

    int t;
    scanf("%d",&t);
    for (int i = 0; i < t; ++i)
    {
        int n;
        scanf("%d",&n);
        if(n == -1){
            // printf("Hi11");
            pop();
            disp();
        }
        else{
            // printf("Hi");
            push(n);
            disp();
        }


    }
    
    return 0;
}
