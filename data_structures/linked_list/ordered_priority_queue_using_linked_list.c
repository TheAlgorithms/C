#include <stdio.h>
#include <stdlib.h>
//node structure
 struct node{
  int info;
 struct node * next;
};
typedef struct  node node;
// creates and returns a node with info as k and next as NULL
node * create(int k){
    node *p=(node *)malloc(sizeof(node));
    p->info=k;
    p->next=NULL;
    return p;
}
// returns 1 if a node is empty. Else 1
int isempty(node * first){
    if(first==NULL){
        return 1;
    }
    return 0;
}
// returns the maximum value of the pq using a flag to check whether the queue is empty
void maximum(node * first,int * k,int * flag){
    if(isempty(first)){
        *flag=0;
    }
    else{
        *flag=1;
        *k=first->info;
    }
    return;
}
// extracts and returns the maximum value of the pq using a flag to check whether the queue is empty
void extract_max(node ** first,int * k,int * flag){
    if(isempty(*first)){
     *flag=0;
     return ;   
    }
    *flag=1;
    *k=(*first)->info;
    node * p=*first;
    *first=p->next;
    free(p);
}
// inserts a new val k into the pq at it's correct position
void insert(node * * first,int k){
    node * p=*first;
    if(p==NULL){
        *first=create(k);
        return;
    }
    node * q=NULL;
    while(p!=NULL && p->info>=k){
        q=p;
        p=p->next;
    }
    if(q==NULL){
        p=create(k);
        p->next=*first;
        *first=p;
    }
    else{
        q->next=create(k);
        q->next->next=p;
    }
}
// returns the pointer with the first occurence of the value k. Returns NULL if it's not present
node * list_search(node * first, int k){
    node * p=first;
    while(p!= NULL){
        if(p->info==k){
            return p;
        }
        p=p->next;
    }
    return NULL;

}
// finds and increases the value of first occurence of k to newval
void increase_key(node ** first,int k,int newval){
    if(newval<=k){
        printf("The new value is not greater than the previous\n");
        return;
    }
    else{
        node * pos=list_search(*first,k);
        if(pos==NULL){
            printf("The value %d is not present in the queue\n",k);
            return;
        }
        if(pos==*first){
            return;
        }
        node * q=*first;
        while(q->next != pos){
            q=q->next;
        }
        q->next=pos->next;
        free(pos);
        insert(first,newval);

    }
}
// displays the pq
void display(node * first){
  node * p=first;
  while(p != NULL){
      printf("%d ",p->info);
      p=p->next;
  }
  printf("\n");
}
int main(){
    char c;
    node * first=NULL;
    int k,n;
    c='0';
    printf("p : prints the maximum value that is present in the queue\n");
    printf("m : extracts and prints the maximum value\n");
    printf("i : (followed by an integer) inserts a new value to pq\n");
    printf("k : (followed by two integers- prev and new value) increases the value of a previous element\n");
    printf("d : displays the priority queue\n");
    printf("e : exits the program\n");
    while(c!='e'){
        scanf("%c%*c",&c);
        switch(c){
            case 'p':maximum(first,&k,&n);
                        if(n){
                            printf("%d\n",k);
                        }
                        else{
                            printf("The queue is empty\n");
                        }
                        break;
            case 'm': extract_max(&first,&k,&n);
                        if(n){
                            printf("%d\n",k);
                        }
                        else{
                            printf("The queue is empty\n");
                        }
                        break;
            case 'i':   scanf("%d%*c",&k);
                        insert(&first,k);
                        break;
            case 'k':   scanf("%d%*c",&k);
                        increase_key(&first,k,n);
                        break;
            case 'd': display(first);
                        break;
                    
        }
    }
    return 0;
}