#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
	int roll;
	char name[20];
	//float percent;
	struct student *next_item;
};
struct student *head=NULL,*tail=NULL;//it points that list doesnot contain any data
int n;
void add()
{
	struct student *ptr;
	ptr=(struct student*)malloc(sizeof(struct student));
	fflush(stdin);
	printf("Enter name, roll, precentage accordingly\n ");
	scanf("%s %d",ptr->name,&ptr->roll);//or we can input name of a student with using & oprator
	ptr->next_item=NULL;
	
	if(head==NULL)
	head=tail=ptr;
	else
	{
		tail->next_item=ptr;
		tail=ptr;
	}
	n++;
}
void insert(int pos){
//printf("Enter the  position : ");
//scanf("%d",&pos);
struct student *p=NULL;
struct student *q=head;
int c=1;

if(pos<1||pos>n+1)
printf("Insertion is not possible ");
else{
p=(struct student *)malloc(sizeof(struct student));
printf("Enter the name and roll and percentage accordingly : ");
fflush(stdin);
gets(p->name);
scanf("%d",&p->roll);
if(pos==1 && head==NULL)
{
	head=tail=p;
	p->next_item=NULL;
}
else if(pos==1 && head!=NULL){
	p->next_item=head;
	head=p;
}
else{
	q=head;
	while(c<pos-1)
	   {
		
			q=q->next_item;
			c++;
		}
		p->next_item=q->next_item;
        q->next_item=p;
		if(p->next_item==NULL)
		tail=p;
	}
	n++;

}
}
void display(){
	struct student *ptr=head;
	printf("The list is \n");
	while(ptr!=NULL)
	{
	
		printf("\n%s  %d ",ptr->name,ptr->roll);
	//	fflush(stdout);
		ptr = ptr->next_item;
	}
}
void search(int ser){
	struct student *q=head;
	int count=1,val=0;
	q=head;
	while(q!=NULL)
	{
       if(q->roll==ser)
	   {
		val=1;
		break;
	   }
	   q=q->next_item;

	   count++;
	}
	if(val==0)
	printf("Data not found ");
	else
	printf("data found at %d",count);
	char ch;
	while(1){
		printf("\nEnter B for insert before and A for after before and D for display E for exit : ");
	fflush(stdin);
	scanf("%c",&ch);
	
		switch(ch)
		{
			case 'B':
			insert(count);
			break;
			case 'A':
			insert(count+1);
			break;
			case 'D':
			display();
			break;
			case 'E':
			exit(0);
			default:
			printf("Enter a valid operator .");
		}
	}

}
int main(){
	char ch;
	int pos,ser;
	
	while(1){
	
		printf("\nEnter A for add and D for display and I for insert and S for search E for exit: ");
		fflush(stdin);
	scanf("%c",&ch);
		switch(ch){
			case 'A':
				add();
				break;
			case 'D':
				display();
				break;
				case 'I':
				
				printf("Enter the  position : ");
				scanf("%d",&pos);
				insert(pos);
				break;
				case 'S':
				printf("Enter the data to be searched : ");
				scanf("%d",&ser);
				search(ser);
			case 'E':
				exit(0);
			default :
				printf("\nEnter a valid keyword");
		}
	}
	return 0;
}