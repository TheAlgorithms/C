#include<stdio.h>
#define ROW 7
#define COL 5

    static int x = -1;
    static int y = -1;
    enum movement {FORWARD, BACKWARD, UP, DOWN}move;

    void Maze(int arr[ROW][COL], int row, int column,int ansr[30],int ansc[30],enum movement move)
    {
        int i;
        if (arr[row][column] == 1)//If there is a path
        {
        ansr[++x] = row;
        ansc[++y] = column;
        if ((column == COL - 1) && (row == ROW-1))//Rat has reached exit
        {
            printf("\nSolution\n");
            for (i = 0; i <= x; i++)

            {
            printf("(%d,%d)\n ",ansr[i], ansc[i]);
            }
         //   getch();
    //        exit(0);
        }
        else if(column == COL-1)//Last column
        {
            if(move == DOWN)//Moved from last column down
            {
              if(arr[row+1][column] == 0)
              {
                Maze(arr, row, column-1, ansr, ansc,BACKWARD);//Move to previous column
              }
            }
            Maze(arr,row+1,column,ansr,ansc,DOWN);//Move to next row
        }
        else if(row == ROW-1)//Last row
        {
            if(move == FORWARD)
            {
              if(arr[row][column+1] == 0)
              {
                Maze(arr, row-1, column, ansr, ansc,UP);//Move to previous column
              }
            }
            Maze(arr,row,column+1,ansr,ansc,FORWARD);//Move to next column
        }
        else if(move == BACKWARD)
        {
            if(arr[row+1][column] == 1)
               Maze(arr, row+1, column, ansr, ansc,DOWN);//Move to next row
            else if(arr[row][column-1] == 1)
               Maze(arr, row, column-1, ansr, ansc,BACKWARD);
            else if(arr[row-1][column] == 1)
               Maze(arr, row-1, column, ansr, ansc,UP);
        }
        else if(move == UP)//Moved up
        {
          if(arr[row][column-1] == 1)
            Maze(arr, row, column-1, ansr, ansc,BACKWARD);//Move to previous column
          else
            Maze(arr, row, column+1, ansr, ansc,FORWARD);
        }
        else
        {
            Maze(arr, row, column + 1, ansr, ansc,FORWARD);//Move to next column
            Maze(arr, row + 1, column, ansr, ansc,DOWN);//Move to next row

          if((arr[row][column+1] == 0) && (arr[row+1][column] == 0))
          {
            Maze(arr, row, column-1, ansr, ansc,BACKWARD);//Move to previous column
          }
        }
        }//if

        if((ansr[x] == row) && (ansc[y] == column))//Erase the paths bactracked
        {
        ansc[y--]=0;
        ansr[x--]=0;
        }
    }//Maze

void main()
{
        int arr[ROW][COL],i,j,row,col;//Maze
        int ansr[30] = { 0 };//Row value of solution
        int ansc[30] = { 0 };//Column value of solution
        //clrscr();
        //Input with either 0/1
	printf("Enter (%d(rows)*%d(columns)) elements of maze\n",ROW,COL);
        for (i = 0; i < ROW; i++)
	        {
		        for (j = 0; j < COL; j++)
		        {
			        scanf("%d",&arr[i][j]);
		        }
	        }
        printf("Maze Structure\n");
        for (i = 0; i < ROW; i++)
        {
	        for (j = 0; j < COL; j++)
	        {
	            printf("%d ",arr[i][j]);
        	}
        	printf("\n");
        }
  	      Maze(arr,0,0,ansr,ansc,FORWARD);//Rat starts at location (0,0)
	      //printf("No solution");
       // getch();
    }
