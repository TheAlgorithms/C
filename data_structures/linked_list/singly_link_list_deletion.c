/* 
 *Includes structure for a node which can be use to make new nodes of the Linked List. 
 *It is assumed that the data in nodes will be an integer, though 
 *function can be modified according to the data type, easily. 
 *deleteNode deletes a node when passed with a key of the node.
*/

#include<stdio.h>

struct node
{
	int info;
	struct node *link;
};

struct node *start = NULL;

struct node *createnode()
{
	struct node *new;
	new = (struct node*)malloc(sizeof(struct node));
	if (new == NULL) {
		new = NULL;
		goto out_failure;
	}
	
out_success:
	return new;
out_failure:
	return new;
}

void insert()
{
	struct node *p;
	p = createnode();

	printf("\nenter the number to insert");
	scanf("%d",&p->info);

	p->link=NULL;

	if(start==NULL){
		start=p;
	}else{
		p->link=start;
		start=p;
	}
}

void deleteion()
{
	struct node *t;
	if(start==NULL)
	{
		printf("\nlist is empty");
	}
	else
	{
		struct node *p;
		p=start;
		start=start->link;
		free(p);
	}
}

void viewlist()
{
	struct node *p;
	if(start==NULL)
	{
		printf("\nlist is empty");
	}
	else
	{   p=start;
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->link;
		}
	}
}

int main()
{
    int n;

    while(1)
    {
        printf("\n1.add value at first location");
        printf("\n2.delete value from first location");
        printf("\n3.view value");
        printf("\nenter your choice");
        scanf("%d",&n);

	switch(n)
        {
        case 1:
		insert();
		break;
        case 2:
		deleteion();
		break;
        case 3:
		viewlist();
		break;
        default:
		printf("\ninvalid choice");
        }
    }
    return(0);
}
