#include<stdio.h> 
#include<stdlib.h>

int nns=0;

struct stack{
    struct vertex *item;
    struct stack *prv;
};

struct stack *top = NULL;

struct queue{
    struct vertex *item; 
    struct queue *next; 
    struct queue *prv;
};

struct queue *end = NULL; 
struct queue *start = NULL;

void ENQUEUE(struct vertex *node)
{

    struct queue *new = (struct queue*)malloc(sizeof(struct queue)); 
    new->item = node;
    new->next = NULL;

    if(start == NULL)
    {
        new->prv = NULL; start = end = new;
    }
    else
    {
        new->prv = end; end = new;
    }

    return;
}



struct vertex* DEQUEUE()
{
    struct vertex *del = start->item; 
    if(end != start)
        start = start->next; else
    {
        start = end = NULL;
    }
    return del;
}





// Main list representation 
struct vertex{

    int data;
    // Link to conncections 
    struct connections *link;
    // Link to the next vertex 
    struct vertex *next;
};


void push(struct vertex *node)
{

    struct stack *new = (struct stack*)malloc(sizeof(struct stack)); 
    new->item = node;
    new->prv = top; top = new;
    return;
}



struct vertex* pop()
{
    struct vertex *del = top->item; 
    top = top->prv;
    return del;
}





struct vertex *head = NULL;

// Vertex list representation
struct connections{
    // Link to the next vertex 
    struct vertex *link;
    // Link to the next element 
    struct connections *next;
};


void add_connections(int a, struct vertex *ptr)
{

    int flag = 0;
    struct vertex *rand = ptr; 
    int x = ptr->data;

    if(ptr->link == NULL)
    {
        flag = 1;
        ptr->link = (struct connections*)malloc(sizeof(struct connections)); (ptr->link)->link = NULL;
        (ptr->link)->next = NULL;
    }
    
    struct connections *node = ptr->link;

    while(node->next != NULL) 
    node = node->next;
    
    ptr = head;
    
    for(int i=1; i<a; i++) 
    ptr = ptr->next;

    struct connections *new = (struct connections *)malloc(sizeof(struct connections)); 
    
    if(flag != 1)
    {
        node->next = new; 
        new->link = ptr; 
        new->next = NULL;
    }

    else
    {
        rand->link = new; 
        new->link = ptr; 
        new->next = NULL;
        printf("Link from %d is %d",rand->data, ((rand->link)->link)->data);
    }

}


void add_vertex(int in[], int out[], int n1, int n2, int data)
{

    // Create new vertex 
    int vt_no=0; nns+=1;
    struct vertex *temp = head, *new = (struct vertex *)malloc(sizeof(struct vertex));
    if(temp != NULL)
    {    
        while(temp->next != NULL)
        {
            temp = temp->next; vt_no+=1;
        }

        vt_no+=2;
        temp->next = new; 
        new->data = data; 
        new->next = NULL; 
        new->link = NULL;
    }

    else
    {

        head = (struct vertex *)malloc(sizeof(struct vertex)); 
        head->data = data;
        head->next = NULL; 
        head->link = NULL; 
        return;
    }


    // Inward links to the new node 
    for(int i=0; i<n1; i++)
    {
        struct vertex *ptr = head; 
        
        for(int k=1; k<in[i]; k++) 
        ptr = ptr->next;
        
        add_connections(vt_no, ptr);
    }



    // Outward links from new node 
    for(int i=0; i<n2; i++)
    {
        add_connections(out[i], new);
    }
    printf("\nVertex successfully added!!");
}

void matrix_graph()
{

    int arr[nns-1][nns-1]; 
    struct vertex *top = head; 
    struct connections *start; 
    
    for(int i=0; i<nns; i++)
    {
        start = top->link;
        for(int j=0; start != NULL;j++)
        {
            if(j+1 == (start->link)->data)
            {
                arr[i][j] = 1;
                start = start->next;
            }

            else arr[i][j]=0;
        }

        top = top->next;
    }

    printf("\nPrinting array...\n");

    for(int i=0; i<nns; i++)
    {
        for(int j=0; j<nns; j++) 
        printf("%d ", arr[i][j]); 
        printf("\n");
    }
}

int visit(int arr[], int *n, int x)
{
    int flag = 0;
    for(int i=0; i<*n; i++)
    {

        if(x == arr[i])
        {
            flag = -1; 
            break;
        }
    }

    arr[++(*n)] = x;
    return flag;
}



void DFS()
{

    int arr[100], n=0;; top = NULL; 
    push(head); 
    
    while(top!= NULL)
    {
        struct vertex *node = pop();

        if(visit(arr, &n, node->data) == -1) 
        continue;
        
        else
        {
            printf("%d ", node->data);
        }

        struct connections *temp = node->link; 
        
        while(temp != NULL)
        {
            push(temp->link);
            // n++;
            temp = temp->next;
        }
    }

    printf("\n");
}

void BFS()
{

    int arr[100], n=0;;


    ENQUEUE(head);
    while(end!= NULL)
    {
        struct vertex *node = DEQUEUE();
        if(visit(arr, &n, node->data) == -1) 
        continue;
        else
        {
            printf("%d ", node->data);
        }

        struct connections *temp = node->link; 
        
        while(temp != NULL)
        {
            ENQUEUE(temp->link);
            // n++;
            temp = temp->next;
        }
    }

    printf("\n");
}

void display()
{

    struct vertex *ptr = head; 
    int i = 0;
    printf("\nNo.\t\tData\t\tLinks"); 
    
    while(ptr != NULL)
    {

        printf("\n%d.\t\t%d\t\t",++i, ptr->data); 
        struct connections *temp = ptr->link;
        while(temp != NULL)
        {

        struct vertex *node = temp->link; printf("%d\t", node->data);
        temp = temp->next;
        }
        ptr = ptr->next;
    }
}



int return_node_count()
{

    struct vertex *ptr = head; 
    int count = 1;
    while(ptr->next != NULL)
    {
        count+=1;
        ptr = ptr ->next;
    }

    return count;
}



void add()
{

    if(head == NULL)
    {
        printf("\nPlease enter the first node of the graph - "); 
        int a;
        scanf("%d", &a);
        printf("\nFirst vertex successfully added!!");
        add_vertex(NULL, NULL, 0, 0, a);
    }

    else
    {

        printf("\nPlease enter the next node of the graph - "); 
        int a, n1, n2;
        scanf("%d", &a);
        printf("\nPlease enter the number of vertices which link towards this node - "); 
        scanf("%d", &n1);
        printf("\nPlease enter the number of vertices which link away from this node - "); 
        scanf("%d", &n2);

        int linkin[n1], linkout[n1];

        if(n1 != 0)
        printf("\nPlease enter the vertex numbers (1-%d) which link towards this node - ", return_node_count());
        
        for(int i=0; i<n1; i++)
        {

            int x; 
            scanf("%d", &x);
            if(x <= return_node_count()) 
            linkin[i] = x;
            else
            {
                printf("\nNode not present in graph!! Please enter a different node - "); 
                i-=1;
            }
        }

        if(n2 != 0)
        printf("\nPlease enter the vertex numbers (1-%d) which link outwards from node - ", return_node_count());

        for(int i=0; i<n2; i++)
        {

            int x; 
            scanf("%d", &x);
            if(x <= return_node_count()) 
                linkout[i] = x;
            else
            {

            printf("\nNode not present in grapph!! Please enter a different node - "); 
            i-=1;
            }
        }
        add_vertex(linkin, linkout, n1, n2, a);
    }
}



void main()
{
    while(1)
    {

        printf("\n\n\t\tMenu"); 
        printf("\n\t\t~~~~"); 
        printf("\n\t1. Add a vertex");
        printf("\n\t2. Display the graph"); 
        printf("\n\t3. DFS"); 
        printf("\n\t4. BFS");
        printf("\n\t5. Exit");
        printf("\n\n\tPlease enter your choice (1-5) - "); 
        int ch;
        scanf("%d", &ch);

        if(ch == 5) 
        break;

        switch(ch)
        {
            case 1:
            {
                add();
                break;
            }

            case 2:
            {
                display(); 
                matrix_graph(); 
                break;
            }

            case 3:
            {
                printf("\nDFS of the graph is "); 
                DFS();
                break;
            }

            case 4:
            {

                printf("\nBFS of the graph is "); 
                BFS();
                break;
            }

            case 5:
            {
                break;
            }
        }

    }
return;
}
