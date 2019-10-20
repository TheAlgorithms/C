/*
Sorted circular Double Linked List.
Sort the list at the input, moving the pointers, not the node values
Includes a function to allocate memory for new nodes.
It is assumed that the data in nodes will be an integer, though
function can be modified according to the data type, easily.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct list list;
typedef struct node node;

struct node{
    int data;
    node *previous;
    node *next;
};

struct list{
    node *first;
    int size;
};

//Function to create the list
list *create_list(){
    list *l = (list*) malloc(sizeof(list));
    if (l == NULL) {
        return NULL;
    }
    else{
        l->first = NULL;
        l->size=0;
        return l;
    }
}

//Function to create the node
node *create_node(int data){
  node *n = (node*) malloc(sizeof(node));
  if(n!=NULL){
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
int isEmpty(list *l){
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
node *search_l(list *l, int k){
    node *aux = l->first;
    while(aux != NULL){
        if(aux->data == k){
            return aux;
        }
        aux = aux->next;
        if(aux == l->first->next){
            break;
        }
    }
    printf("There is not one node with this key\n");
    return NULL;
}

//Insert the node in the circular list
//Receive a pointer to the list and a pointer to the x node, the node you want to insert
//Return a pointer to node in the list
node *insert(list *l, node *x){
    if(isEmpty(l) == 1){
        l->first = x;
        l->first->next = x;
        l->first->previous = x;
    }
    else{
      if(x->data < l->first->data){
        x->next = l->first;
        x->previous = l->first->previous;
        l->first->previous->next = x;
        l->first->previous = x;
        l->first = x;
      }
        else{
            node *aux = l->first;
            while(x->data >= aux->data){
                if(x->data <= aux->next->data || aux->next == l->first){
                    x->next = aux->next;
                    aux->next->previous = x;
                    x->previous = aux;
                    aux->next = x;
                    break;
                }
                aux = aux->next;
            }
        }
    }
    l->size++;
    return x;
}

//Function to remove a node in the list
//Receive a pointer to the list and a pointer to the node you want to remove
//Return a pointer to removed node -> Facilitates the purge function, or NULL if the list is empty
node *remove_l(list *l, node *k){
    if(isEmpty(l) == 1) {
        return NULL;
    }
    if(search_l(l, k->data) == NULL){
        return NULL;
    }
    if(l->size == 1){
        node *aux = l->first;
        aux->next = NULL;
        aux->previous = NULL;
        l->first = NULL;
        return NULL;
    }
    else{
        if(l->first == k){
            l->first->previous = l->first->next;
            l->first->next = l->first->previous;
            l->first->previous = NULL;
            node *aux = l->first->next;
            l->first->next = NULL;
            l->first = aux;
            aux = NULL;
        }
        else{
            node *x = l->first;
            while(x->next !=NULL){
                if(x->next == k){
                    x->next = k->next;
                    k->next->previous = k->previous;
                    break;
                }
                else{
                    x = x->next;
                }
                if (x == l->first){
                    return NULL;
                }
            }
        }
        k->next = NULL;
        k->previous = NULL;
        l->size--;
        return k;
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
            if(aux == l->first->previous){
                break;
            }
		}
	}
}

//Erase all data and deallocate memory for all nodes and list
//Receive a pointer to the list
void *purge(list *l){
    node *aux_first = l->first;
    while(l->first != NULL){
        node *aux = l->first;
        free(remove_l(l, aux));
        l->first = aux->next;
    }
    free(l);
    l->size = 0;
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

//Print the sorted list
	printf("First test: Printing list\n");
	print_l(list_aux);
//Note that even if you insert out of order, it is printed in the order

//There's two 0s in the list, after remove both, need to print that doesn't exist
	printf("\n\nSecond test: Remove node");

	node *no = search_l(list_aux, 0);
	printf("\nExist the a node with: %d\n", no->data);
	remove_l(list_aux, n01);
	remove_l(list_aux, n07);
	search_l(list_aux, 0);
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
