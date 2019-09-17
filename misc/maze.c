#include<stdio.h>
#include<stdlib.h>

typedef struct{
	short int row;
	short int col;
	short int dir;
}element;

typedef struct{
	short int horiz;
	short int vert;
}move;

void directions(move[]);
void game();
void push(element[],int*,element);
element pop(element[],int*);
void display(element[],int*);

int main()
{	
	game();
	return 0;
}

void game()
{
	int **maze,**mark,nextRow,nextCol,row,column,i,j,TOP=-1;
	element current,stack[50];
	move offsets[8];

	directions(offsets);
	
	scanf("%d%d",&row,&column);
	
	maze=(int**)malloc((row+2)*sizeof(int*));
	for(i=0;i<row+2;i++)
	{
		*(maze+i)=(int*)malloc((column+2)*sizeof(int));
	}
	mark=(int**)malloc((row+2)*sizeof(int*));
	for(i=0;i<row+2;i++)
	{
		*(mark+i)=(int*)malloc((column+2)*sizeof(int));
	}
	for(i=0;i<row+2;i++)
	{
		for(j=0;j<column+2;j++)
		{
			*(*(mark+i)+j)=0;
		}
	}

	for(i=0;i<row+2;i++)
	{
		for(j=0;j<column+2;j++)
		{
			if(i==0||i==row+1||j==0||j==column+1)
			{
				*(*(maze+i)+j)=1;
			}
			else
			{
				scanf("%d",(*(maze+i)+j));
			}
		}
	}

	
	current.dir=0;
	current.row=1;
	current.col=1;

	printf("\nStarting at (1,1)\n");

	while(current.dir<8&&(current.row!=row||current.col!=column))
	{
		nextRow=current.row+offsets[current.dir].vert;
		nextCol=current.col+offsets[current.dir].horiz;

		if(maze[nextRow][nextCol]==0&&mark[nextRow][nextCol]!=1)
		{

			mark[current.row][current.col]=1;
			push(stack,&TOP,current);
			current.dir=0;
			current.row=nextRow;
			current.col=nextCol;
		}
		else
		{
			current.dir++;
		}

		if(current.dir==8)
		{
			current=pop(stack,&TOP);
		}
	}	
			
	display(stack,&TOP);

	printf("End at (%d,%d)\n",row,column);

}

void display(element stack[],int *TOP)
{
	int copyTOP=1;
	while(copyTOP<=*TOP)
	{
		printf("Move at (%d,%d)\n",stack[copyTOP].row,stack[copyTOP].col);
		copyTOP++;
	}
}

void push(element stack[],int *TOP,element value)
{
	*TOP=*TOP+1;
	stack[*TOP].row=value.row;
	stack[*TOP].col=value.col;
	stack[*TOP].dir=value.dir+1;
}

element pop(element stack[],int *TOP)
{
	*TOP=*TOP-1;
	return stack[*TOP+1];
}

void directions(move offset[])
{
	offset[0].vert=-1;
	offset[0].horiz=0;
	offset[1].vert=-1;
	offset[1].horiz=1;
	offset[2].vert=0;
	offset[2].horiz=1;
	offset[3].vert=1;
	offset[3].horiz=1;
	offset[4].vert=1;
	offset[4].horiz=0;
	offset[5].vert=1;
	offset[5].horiz=-1;
	offset[6].vert=0;
	offset[6].horiz=-1;
	offset[7].vert=-1;
	offset[7].horiz=-1;
}
