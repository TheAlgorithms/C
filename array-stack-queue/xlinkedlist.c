
// lab program for single linked list. Same can be used to impliment stacks and queues using appropiate functions


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char usn[100],name[100],branch[100],sem[100];
	int phno;
	struct node *link;
};



// declaring the start pointer globally
struct node * start=NULL;

void create(int);
void insertfront();
void insertback();
void delfront();
void delback();
void display();



void main()
{
	int ch,n;


	do
	{
		printf("Enter 1 to create\n2To insert in the front\n3To  insert at the end\n4To delete at the front\n5To delete at the back\n6 To display\n7 To Exit");
		scanf("%d",&ch);


		switch(ch)
		{
			case 1: printf("Enter the number of nodes\n");
				scanf("%d",&n);
				create(n);
				break;
			case 2:insertfront();
				break;
			case 3:insertback();
				break;
			case 4: delfront();
				break;
			case 5: delback();
				break;
			case 6:display();
				break;
			case 7: return;
				break;
			default : printf("INVALID CHOICE");
		}
	}while(ch!=7);
}



void insertfront()
{
	//Using 1 after variable name to differentiate between inputs and structure variables
	struct node *temp;
        char usn1[100],name1[100],branch1[100],sem1[100];
        int phno1;
	


	//Checking if temp points to a valid address
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("Insufficent memory");
		exit(0);
	}



	//Inputing data from the user	

	printf("Enter the USN\n");
	scanf("%s",usn1);
	printf("Enter the Name\n");
        scanf("%s",name1);
	printf("Enter the branch\n");
        scanf("%s",branch1);
	printf("Enter the sem\n");
        scanf("%s",sem1);
	printf("Enter the phno\n");
	scanf("%d",&phno1);


	//Copying data to structure 
	strcpy(temp->usn,usn1);
	strcpy(temp->name,name1);
	strcpy(temp->sem,sem1);
	strcpy(temp->branch,branch1);
	temp->phno=phno1;


	//Creating the node



	//Checking if linked list if empty then this becomes first node
	if(start==NULL)
	{
		start=temp;
		temp->link=NULL;
	}
	else //Inserting at the front
	{
		temp->link=start;
		start=temp; // Becomes the first node
	}
}






void insertback()
{
        //Using 1 after variable name to differentiate between inputs and structure variables
        struct node *temp;
        char usn1[100],name1[100],branch1[100],sem1[100];
        int phno1;
        


        //Checking if temp points to a valid address
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("Insufficent memory");
                exit(0);
        }

        

        //Inputing data from the user   
        
        printf("Enter the USN\n");
        scanf("%s",usn1);
        printf("Enter the Name\n");
        scanf("%s",name1);
        printf("Enter the branch\n");
        scanf("%s",branch1);
        printf("Enter the sem\n");
        scanf("%s",sem1);
	printf("Enter the phno\n");
        scanf("%d",&phno1);


        //Copying data to structure 
        strcpy(temp->usn,usn1);
        strcpy(temp->name,name1);
        strcpy(temp->sem,sem1);
        strcpy(temp->branch,branch1);
        temp->phno=phno1;


        //Creating the node



        //Checking if linked list if empty then this becomes first node
        if(start==NULL)
        {
                start=temp;
                temp->link=NULL;
        }
        else //Inserting at the end
        {
		struct node *dstart=start; // Creating duplicate start to traverse through the linked list
		

		while(dstart->link != NULL)
			dstart=dstart->link;    // Makes dstart point to the last node 
		

		dstart->link=temp;
		temp->link=NULL; // temp becomes the last node           

       }
}





// Creating n nodes


void create(int n)
{
	int i;
	

	// we can create N nodes be calling the function to insert at the end n times
	
	for(i=1;i<=n;i++)
		insertback();
}





// Deleting from the front

void delfront()
{

	//Check if linked list is emepty
	if(start==NULL)
		printf("Linked list is emepty");
	else // Remove the first node;
	{
		
		free(start);// memory allocated dynamically has to be freed
		start=start->link;
	}
}





//deleted from the back


void delback()
{
	
	 //Check if linked list is emepty
        if(start==NULL)
                printf("Linked list is emepty");
        else // Remove the last  node;
	{
		struct node *dstart=start; // duplicate strat to traverse the list
		struct node *prev=dstart; // node to get the adress of second last node


		while(dstart->link!=NULL)
		{
			prev=dstart;  // Points to second last node
			dstart=dstart->link; // points to last node
					
		}
		

		prev->link=NULL;
		free(dstart);  // Dynamically allocated memory has to be freed
		dstart=NULL; // Dangeling pointer as it points to a location no longer avalable;


	}

}

	
	
void display()
{

	struct node *dstart=start;// variable to traverse the node
	printf("\n\n\n\n\n");
	while(dstart != NULL)
	{
		printf("USN is \n");
		puts(dstart->usn);
		printf("Name is \n");
		puts(dstart->name);
		printf("Branch is\nn");
		puts(dstart->branch);
		printf("Sem isx\n");
		puts(dstart->sem);
		printf("phone number is \n");
		printf("%d",dstart->phno);
		dstart=dstart->link;
		printf("\n\n\n");
	}

}







































