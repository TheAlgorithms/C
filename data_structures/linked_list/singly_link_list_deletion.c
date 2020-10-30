/*Includes structure for a node which can be use to make new nodes of the Linked
  List. It is assumed that the data in nodes will be an integer, though function
  can be modified according to the data type, easily. deleteNode deletes a node
  when passed with a key of the node.
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *start = NULL;
///////////////////////////////////////////////////////////
struct node *createnode()  // function to create node
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    return (t);
}
////////////////////////////////////////////////////////
void insert()  // function to insert at first location
{
    struct node *p;
    p = createnode();
    printf("\nEnter the number to insert: ");
    scanf("%d", &p->info);
    p->link = NULL;
    if (start == NULL)
    {
        start = p;
    }
    else
    {
        p->link = start;
        start = p;
    }
}
///////////////////////////////////////////////////////////
void deletion()  // function to delete from first position
{
    struct node *t;
    if (start == NULL)
    {
        printf("\nList is empty.\n");
    }
    else
    {
        struct node *p;
        p = start;
        start = start->link;
        free(p);
    }
}
///////////////////////////////////////////////////////
void viewlist()  // function to display values
{
    struct node *p;
    if (start == NULL)
    {
        printf("\nList is empty.\n");
    }
    else
    {
        p = start;
        printf("\n");
        while (p != NULL)
        {
            printf("%d ", p->info);
            p = p->link;
        }
        printf("\n");
    }
}
//////////////////////////////////////////////////////////////////////

int main()
{
    int n;
    while (1)
    {
        printf("\n1. Add value at first location");
        printf("\n2. Delete value from first location");
        printf("\n3. View value");
        printf("\nEnter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            insert();
            break;
        case 2:
            deletion();
            break;
        case 3:
            viewlist();
            break;
        default:
            printf("\ninvalid choice.\n");
        }
    }
    return (0);
}
