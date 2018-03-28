/*
A Maze is given as N*N binary matrix of blocks where source block is the upper left most block 
i.e., maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. A rat starts 
from source and has to reach destination. The rat can move only in two directions: forward and down.
In the maze matrix, 0 means the block is dead end and 1 means the block can be used in the path from source to destination.
*/
#include<stdio.h>
#define N 4 
 
int solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);
 
void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}
 
int isSafe(int maze[N][N], int x, int y)
{
    // if (x,y outside maze) return false
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return 1;
 
    return 0;
}
 
int solveMaze(int maze[N][N])
{
    int sol[N][N] = { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
 
    if(solveMazeUtil(maze, 0, 0, sol) == 0)
    {
        printf("Solution doesn't exist");
        return 0;
    }
 
    printSolution(sol);
    return 1;
}
 
/* A recursive utility function to solve Maze problem */
int solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
    if(x == N-1 && y == N-1)
    {
        sol[x][y] = 1;
        return 1;
    }
 
    if(isSafe(maze, x, y) == 1)
    {
        // mark x,y as part of solution path
        sol[x][y] = 1;
 
        /* Move forward in x direction */
        if (solveMazeUtil(maze, x+1, y, sol) == 1)
            return 1;
 
        /* If moving in x direction doesn't give solution then
           Move down in y direction  */
        if (solveMazeUtil(maze, x, y+1, sol) == 1)
            return 1;
 
        /* If none of the above movements work then BACKTRACK: 
            unmark x,y as part of solution path */
        sol[x][y] = 0;
        return 0;
    }   
 
    return 0;
}
 
int main()
{
    int maze[N][N]  =  { {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
 
    solveMaze(maze);
    return 0;
}