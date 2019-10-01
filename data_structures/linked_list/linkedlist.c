#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct link{
    char element;
    struct link *next;
} Link;

typedef struct{
    Link *head;
    Link *tail;
    Link *curr;
    int cnt;
} List;

Link *create_link(char it, Link *nextval){
    Link *n;
    n = (Link*) malloc(sizeof(Link));
    n->element = it;
    n->next = nextval;
    return n;
}

Link *create_Link(Link *nextval){
    Link *n;
    n = (Link*) malloc(sizeof(Link));
    (*n).next = nextval;
    return n;
}

List *create_list(){
    List *l;
    l = (List*) malloc(sizeof(List));
    l->head = create_Link(NULL);
    l->tail = l->head;
    l->curr = l->tail;
    l->cnt = 0;
    return l;
}

void clear(List *l){
    Link *temp;
    temp = l->head->next;
    while(l->head != NULL){
        free(l->head);
        l->head = temp;
        temp = l->head->next;
    }
    l->cnt = 0;
    free(l);
}

void insert(List *l, char it){
    l->curr->next = create_link(it, l->curr->next);
    if(l->tail == l->curr){
        l->tail = l->curr->next;
    }
    l->cnt++;
}

void append(List *l,char it){
    l->tail->next = create_link(it, NULL);
    l->tail = l->tail->next;
    l->cnt++;
}

char remove(List *l){
    char it;
    Link *temp;
    if(l->curr->next == NULL){
        return -1;
    }
    it = l->curr->next->element;
    if(l->tail == l->curr->next){
        l->tail = l->curr;
    }
    temp = l->curr->next;
    free(temp);
    l->curr->next = l->curr->next->next;
    l->cnt--;
    return it;
}

void moveToStart(List *l){
    l->curr = l->head;
}

void moveToEnd(List *l){
    l->curr = l->tail;
}

void prev(List *l){
    if(l->curr == l->head){
        return;
    }
    Link *temp;
    temp = l->head;
    while(temp->next != l->curr){
        temp = temp->next;
    }
    l->curr = temp;
}

void next(List *l){
    if(l->curr != l->tail){
        l->curr = l->curr->next;
    }
}

int lenght(List *l){
    return l->cnt;
}

int currPos(List *l){
    Link *temp;
    temp = l->head;
    int i = 0;
    while(l->curr != temp){
        temp = temp->next;
        i++;
    }
    return i;
}

void moveToPos(List *l, int pos){
    if(pos < 0 || pos > l->cnt){
        return;
    }
    l->curr = l->head;
    int i = 0;
    while(i < pos){
        l->curr = l->curr->next;
        i++;
    }
}

char getValue(List *l){
    if(l->curr->next == NULL){
        return -1;
    }
    return l->curr->next->element;
}

#define max 100000

int main(){
    
    return 0;
}
