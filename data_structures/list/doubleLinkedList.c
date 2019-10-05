typedef int item;

typedef struct node {
 	item actualItem;
	struct node *previous;
	struct node *next;
} typeList; 


int insert(typeList **list, item newItem){
    typeList *newList;
   	newList = malloc(sizeof(struct typeList));
	if (!newList) 
		return 0;
      newList->actualItem = newItem;
      newList -> previous = NULL;
      newList -> next = *list;
      if ((*list) != NULL)
         (*list) -> previous = newList;
      *list = newList;
      return 1;
}

int remove (typeList **list, int valor) {
	typeList *newList;
	p=busca(*list,valor);
	if (newList == NULL) 
		return 0; 		    
	if (*list == newList)	
		*list=p->next;		    
	else
		newList->previous->next=newList->next;
	if (newList->next!=NULL) 	 	
		newList->next->previous=newList->previous;	
	free(newList);
	return 1;
}