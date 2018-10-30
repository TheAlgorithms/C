#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FALSE 0
#define TRUE 1

int **maze,**mark,EXIT_ROW,EXIT_COL,top=-1;

typedef struct {
	short int vert;
	short int horiz;
	}offsets;
offsets move[8];

typedef struct {
	short int row;
	short int col;
	short int dir;
	}element,stack[50];

void path(void)
{
	int i,row,col,nextRow,nextCol,dir,found=FALSE;
	element position;
	mark[1][1]=1, top=0;
	stack[0].row=1;
	stack[0].col=1;
	stack[0].dir=1;
	while(top>-1 && !found){
        	position=pop();
		row=position.row;
		col=position.col;
		dir=position.dir;
	 	while(dir<8  && !found) {
			nextRow=row+move[dir].vert;
			nextCol=col+move[dir].horiz;
			if(nextRow==EXIT_ROW && nextCol==EXIT_COL)
				found=TRUE;
			else if(!maze[nextRow][nextCol] && !mark[nextRow][nextCol]) {
				mark[nextRow][nextCol]=1;
				position.row=row;
				position.col=col;
				position.dir=dir;
				push(position);
				row=nextRow;
				col=nextCol;
				dir=0;
			}
			else
				++dir;
		}
	}
	if(found) {
		printf("The path is:\n");
		printf("row col\n");
		for(i=0;i<=top;i++)
			printf("%2d%5d",stack[i].row,stack[i].col);
		printf("%2d%5d\n",row,col);
		printf("%2d%5d\n",EXIT_ROW,EXIT_COL);
	}
	else
		printf("The maze does not have path\n");
}

int push(int ele)
{
  stack[++top]=ele;
}
int pop()
{
  int ele;
  ele=stack[top--];
  return ele;
}
	  	
int main()
{
  int ran,r,c,i,j,n;
  printf("Enter the no of rows and columns:");
  scanf("%d%d",&r,&c);
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
    ran=rand()%100+1;
    maze[i][j]=ran<60?0:1;
    mark[i][j]=0;
    }
  }
  EXIT_ROW=r;
  EXIT_COL=c;
}
