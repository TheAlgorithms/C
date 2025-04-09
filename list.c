#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int*data;
    int size;
    int capacity;
} List;

void list_init(List*l){
    l->capacity=4;
    l->size=0;
    l->data=malloc(sizeof(int)*l->capacity);
}

void list_resize(List*l){
    l->capacity*=2;
    l->data=realloc(l->data,sizeof(int)*l->capacity);
}

void list_append(List*l,int value){
    if(l->size==l->capacity)
        list_resize(l);
    l->data[l->size++]=value;
}

void list_insert(List*l,int index,int value){
    if(index<0||index>l->size)return;
    if(l->size==l->capacity)
        list_resize(l);
    for(int i=l->size;i>index;--i)
        l->data[i]=l->data[i-1];
    l->data[index]=value;
    l->size++;
}

void list_delete(List*l,int index){
    if(index<0||index>=l->size)return;
    for(int i=index;i<l->size-1;++i)
        l->data[i]=l->data[i+1];
    l->size--;
}

int list_get(List*l,int index){
    if(index<0||index>=l->size)return -1;
    return l->data[index];
}

void list_print(List*l){
    for(int i=0;i<l->size;++i)
        printf("%d ",l->data[i]);
    printf("\n");
}

void list_free(List*l){
    free(l->data);
    l->data=NULL;
    l->size=0;
    l->capacity=0;
}
