#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *first;
	struct node *next;
};

typedef struct node Node;
struct arv{
	Node* root;
};
typedef struct arv Arv;

Node* createNode(int valor);
Arv* createArv(Node* r);
void insert(Node* a,Node* b);
void write(Node *r);

int main(){
	
	Node* a = createnode(1);
	Node* b = createnode(2); 	
	Node* c = createnode(3);
	Node* d = createnode(4);
    
    insert(a,b);
    insert(a,c);
    insert(a,d);
    
    Arv* tree = createArv(a);
    write(a);
}

Node* createnode(int valor){
	Node* a = (Node*)malloc(sizeof(Node));
	a->info = valor;
	a->first = NULL;
	a->next = NULL;
	return a;
}

Arv* createArv(Node *r){
	Arv *a = (Arv*) malloc(sizeof(Arv));
	a->root = r;
	return a;
}

void insert(Node* a,Node* b){
	b->next = a->first;
	a->first = b;
}

void write(Node *r){
	printf("%d",r->info);
	Node* p = (Node*)malloc(sizeof(Node));
	for(p = r->first;p !=NULL;p=p->next){
		write(p);
	}
}

