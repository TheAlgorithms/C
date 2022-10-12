/*Includes structure for a node which can be use to make new nodes of the Linked
  List. It is assumed that the data in nodes will be an integer, though function
  can be modified according to the data type, easily. deleteNode deletes a node
  when passed with a key of the node.
*/
#include <stdio.h>
struct node
{
    int info;
    struct node *link;
};
struct node *start = NULL;

/*function to create node
 */
struct node *createnode()
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    return (t);
}
/*function to insert at first location
 */
void insert()
{
    struct node *p;
    p = createnode();
    printf("\nenter the number to insert");
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
/*insert a node on index `index`*/
void insert_at_index()
{
    struct node *node_before_insertion, *new_node;
    int i, index;
    printf("\nenter the index to insert");
    scanf("%d", &index);
    node_before_insertion = start;
    // loop over the linkedin list until we point to index `index`
    for (i = 1; i < index - 1; i++)
    {
        node_before_insertion = node_before_insertion->link;
    }
    new_node = createnode();
    printf("\nenter the number to insert");
    scanf("%d", &new_node->info);
    new_node->link = node_before_insertion->link;
    node_before_insertion->link = new_node;
}
/*function to delete from first position*/
void deletion()
{
    struct node *t;
    if (start == NULL)
    {
        printf("\nlist is empty");
    }
    else
    {
        struct node *p;
        p = start;
        start = start->link;
        free(p);
    }
}
/*function to display values*/
void viewlist()
{
    struct node *p;
    if (start == NULL)
    {
        printf("\nlist is empty");
    }
    else
    {
        p = start;
        while (p != NULL)
        {
            printf("%d ", p->info);
            p = p->link;
        }
    }
}

int main()
{
    int n;
    while (1)
    {
        printf("\n1.add value at first location");
        printf("\n2.insert value at index");
        printf("\n3.delete value from first location");
        printf("\n4.view value");
        printf("\nenter your choice");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            insert();
            break;
        case 2:
            insert_at_index();
            break;
        case 3:
            deletion();
            break;
        case 4:
            viewlist();
            break;
        default:
            printf("\ninvalid choice");
        }
    }
    return (0);
}
