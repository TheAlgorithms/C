#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	float frequency;
	char character;
	struct Node *next;
	struct Node *left_child;
	struct Node *right_child;
}node;

node* sort(node*, int);
void display(node*);
node* delete_front(node*);
void huffman_algo(node*);
void print_codes(node*, int[], int);
node* create_node();

node* create_node()
{
	node* temp = (node*)malloc(sizeof(node));
	temp -> next = NULL;
	temp -> left_child = NULL;
	temp -> right_child = NULL;
	return temp;
}

int main()
{
	int n;
	int i;
	node* new_node;
	node* ele;
	node* front_node;
	ele = NULL;
	printf("Enter the number of characters : ");
	scanf("%d", &n);
	for(i = 0; i < n; ++i)
	{
		new_node = create_node();
		printf("Enter the character %d and it's corresponding frequency : ", i + 1);
		scanf(" %c", &(new_node -> character));
		scanf("%f", &(new_node -> frequency));
		if(ele == NULL)
		{
			ele = new_node;
			front_node = new_node;
		}
		else
		{
			ele -> next = new_node;
			ele = ele -> next;
		}
	}
	ele = ele -> next;
	front_node = sort(front_node, n);
	printf("%d\n", n);
	huffman_algo(front_node);
	return 0;
}

node* sort(node* front_node, int n)
{
	int i;
	node* temp;
	node* first_node;
	node* second_node;
	node* curr = create_node();
	for(i = 0; i < n; ++i)
	{
		temp = front_node;
		while(temp -> next != NULL)
		{
			first_node = temp;
			second_node = temp -> next;
			if((first_node -> frequency) > (second_node -> frequency))
			{
				curr -> character = first_node -> character;
				curr -> frequency = first_node -> frequency;
				first_node -> character = second_node -> character;
				first_node -> frequency = second_node -> frequency;
				second_node -> character = curr -> character;
				second_node -> frequency = curr -> frequency;
			}
			temp = temp -> next;
		}
	}
	return front_node;
}

void huffman_algo(node* front_node)
{
	int finished = 0;
	node* temp;
	while(finished != 1)
	{
		temp = create_node();
		float first_freq = front_node -> frequency;
		float second_freq = front_node -> next -> frequency;
		temp -> frequency = first_freq + second_freq;
		if(first_freq < second_freq)
		{
			temp -> left_child = front_node;
		       	temp -> right_child = front_node -> next;
		}
		else
		{
			temp -> left_child = front_node -> next;
			temp -> right_child = front_node;
		}
		front_node = delete_front(front_node);
		front_node = delete_front(front_node);
		if(front_node!=NULL)
		{
			int done = 0;
			node* traverse;
       			traverse = front_node;
			while(traverse -> next != NULL)
			{
				if((traverse -> frequency) <= (temp -> frequency) && ((traverse -> next) -> frequency) >= (temp -> frequency))
				{
					done = 1;
					node* curr;
					curr = traverse -> next;
					traverse -> next = temp;
					temp -> next = curr;
				}
				traverse = traverse -> next;
			}
			if(done == 0)
			{
				if((temp -> frequency) <= (front_node -> frequency))
				{
					temp -> next = front_node;
					front_node = temp;
				}
				else
				{
					node* curr;
					curr = front_node;
					while(curr -> next != NULL)
					{
						curr = curr -> next;
					}
					curr -> next = temp;
				}
			}
		}
		else
		{
			finished = 1;
		}
	}
	int code[100];
	printf("\nCodes:\n");
	print_codes(temp, code, 0);
}

void print_codes(node* temp, int code[], int k)
{
	if(temp -> left_child != NULL)
	{
		code[k] = 0;
		print_codes(temp -> left_child, code, k + 1);
	}
	if(temp -> right_child != NULL)
	{
		code[k] = 1;
		print_codes(temp -> right_child, code, k + 1);
	}
	if((temp -> left_child == NULL) && (temp -> right_child == NULL))
	{
		printf("%c\n", temp -> character);
		int i = 0;
		for(i = 0; i < k; ++i)
		{
			printf("%d", code[i]);
		}
		printf("\n\n");
	}
}

node* delete_front(node* front_node)
{
	node* temp;
	temp = front_node;
	front_node = front_node -> next;
	return front_node;
}

void display(node* front_node)
{
	printf("\n");
	node* temp;
        temp = front_node;
	while(temp != NULL)
	{
		printf("%c", temp -> character);
		printf("\t%f", temp -> frequency);
		printf("\n");
		temp = temp -> next;
	}
	printf("\n");
}
