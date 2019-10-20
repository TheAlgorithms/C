/*
Sorted linkedList.
Sort the list at the input, moving the pointers, not the node values
Includes a function to allocate memory for new nodes.
It is assumed that the data in nodes will be an integer, though
function can be modified according to the data type, easily.
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct list list;
typedef struct node node;

struct list{
    node *first;
    int size;
};

struct node{
    int data;
    node *next;
};

//Function to create the list
list *create_list(){
    list *l = (list*)malloc(sizeof(list)); //Memory allocation
    if (l == NULL) {
        return NULL;
    }
    else{
        l->first = NULL;
        l->size = 0;
		return l;
    }
}

//Function to create the list
node *create_node(int data){
	node *n = (node*) malloc(sizeof(node)); //Memory allocation
	if(n != NULL){
		n->data = data;
		return n;
	}
	else {
		return NULL;
	}
}

//Function to test if the list is empty
//Receive a pointer to the list
//Return 1 if the list is empty or 0 if is not empty
int isEmpty(list* l){
    if (l->first == NULL){
        return 1;
	}
    else{
        return 0;
	}
}

//Function to test if a node is in the list
//Receive a pointer to the list and the data of the node
//Return a pointer to the node if is in the list, or NULL if isn't
node *search(list *l, int k){
    node *aux = l->first;
    while(aux != NULL){
        if(aux->data == k) {
            return aux;
        }
        aux = aux->next;
    }
	printf("Doesn't exit a node with that data\n");
    return NULL;
}

//Insert the node in the list, in a position that makes the list sorted
//Receive a pointer to the list and a pointer to the x node, the node you want to insert
//Return a pointer to node in the list
node *insert(list *l, node *x){
	if(isEmpty(l) == 1){			//If the list is empty, insert in the first position
		l->first = x;
		l->first->next = NULL;
	}
	else{
		if(x->data <= l->first->data){		//Compare the node x with the first node of the list
			x->next = l->first;				//Change position with the first node
			l->first = x;					//Change the first node position
		}
		else{
			node *aux = l->first;
			while(x->data > aux->data){		//While the x node isn't in the right position
				//If the aux->next == NULL means the list is in the end, so will insert there
				if(aux->next == NULL || x->data <= aux->next->data){ //Or if the x node is in the right position
					x->next = aux->next; //Change the position
					aux->next = x;
				}
				aux = aux->next;
				if(aux == NULL) {
					break;
				}
			}
		}
	}
	l->size++; //Increase list size
	return x;
}

//Function to remove a node in the list
//Receive a pointer to the list and a pointer to the node you want to remove
//Return a pointer to removed node -> Facilitates the purge function, or NULL if the list is empty
//or thereisn't the node
node *remove_l(list *l, node *k){
	if(isEmpty(l) == 1) {
		return NULL; //Return NULL if the list is empty
	}
	else{
		if(search(l, k->data) == NULL){
			return NULL;
		}
		if(l->first == k){ //If the node is the first on the list
			l->first = l->first->next; //Just change the pointer of the first for the next position
			k->next = NULL;
			l->size--; //Decrease list size
			return k;

		}
		else{
			node *aux = l->first;
			while(aux->next != NULL){	//While the pointer the list
				if(aux->next == k){
					aux->next = k->next;
					k->next = NULL;
					l->size--; //Decrease list size
					return k;
				}
				else {
					aux = aux->next;
				}
			}
		}
	}
}

//Print all the list
//Receive a pointer to the list
void print_l(list *l){
	if(isEmpty(l) == 1){
		printf("The list is empty\n");
	}
	else{
		node *aux = l->first;
		printf("Size of the list: %d\n", l->size);
		for(int i = 0; i < l->size; i++){
			printf("%d  ", aux->data);
			aux = aux->next;
		}
	}
}

//Erase all data and deallocate memory for all nodes and list
//Receive a pointer to the list
void purge(list* l){
	while(l->first != NULL){
		free(remove_l(l, l->first));
	}
	free(l);
}

int main(){
//Create the list
	list *list_aux = create_list();

//Create all the node
	node *n01 = create_node(0);
	node *n02 = create_node(15);
	node *n03 = create_node(23);
	node *n04 = create_node(77);
	node *n05 = create_node(90);
	node *n06 = create_node(2);
	node *n07 = create_node(0);
	node *n08 = create_node(80);
	node *n09 = create_node(3);
	node *n10 = create_node(4);
	node *n11 = create_node(9);
	node *n12 = create_node(11);
	node *n13 = create_node(12);
	node *n14 = create_node(51);
	node *n15 = create_node(3);

//Inserte the nodes in list
	insert(list_aux, n01);
	insert(list_aux, n02);
	insert(list_aux, n03);
	insert(list_aux, n04);
	insert(list_aux, n05);
	insert(list_aux, n06);
	insert(list_aux, n07);
	insert(list_aux, n08);
	insert(list_aux, n09);
	insert(list_aux, n10);
	insert(list_aux, n11);
	insert(list_aux, n12);
	insert(list_aux, n13);
	insert(list_aux, n14);
	insert(list_aux, n15);

//Print the list
	printf("First test: Printing sort list\n");
	print_l(list_aux);
//Note that even if you insert out of order, it is printed in the order

//There's two 0s in the list, after remove both, need to print that doesn't exist
	printf("\n\nSecond test: Remove node");

	node *no = search(list_aux, 0);
	printf("\nExist the a node with: %d\n", no->data);
	remove_l(list_aux, n01);
	remove_l(list_aux, n07);
	search(list_aux, 0);
	remove_l(list_aux, n07);

//Print the list wihtout both 0
	printf("\nThird test: Printing after remove nodes\n");
	print_l(list_aux);

//Testing purge function
	printf("\n\nFourth test: Printing after purge the list\n");

	purge(list_aux);
	print_l(list_aux);

	return 0;
}
