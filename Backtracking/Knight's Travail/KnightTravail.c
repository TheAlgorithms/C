/*
  The mathematical issue of determining a knight's tour is known as the knight's tour problem.
  A popular challenge assigned to computer science students is to write a software to discover a knight's tour.
*/
  
/*
  Backtracking, similar to the N-Queens Problem, is employed in this code.
*/

#include <stdio.h>
#define N 8

int soveknight(int x, int y, int movei, int sol[N][N],
				int xMove[], int yMove[]);

int notvisited(int x, int y, int sol[N][N])
{
	return (x >= 0 && x < N && y >= 0 && y < N
			&& sol[x][y] == -1);
}
void printSolution(int sol[N][N])
{
    int x,y;
	printf("\n----------------------------------------------------------------\n");
	for (x= 0; x < N; x++) {
		for (y = 0; y < N; y++)
			printf("|  %2d  |", sol[x][y]);
		printf("\n");
		printf("----------------------------------------------------------------");
		printf("\n");
	}
}
int solveKT()
{
	int x,y;
	int sol[N][N];
	for (x = 0; x < N; x++)
		for (y = 0; y < N; y++)
			sol[x][y] = -1;
	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	sol[0][0] = 0;
	if (soveknight(0, 0, 1, sol, xMove, yMove) == 0) {
		printf("No Solution");
		return 0;
	}
	else
		printSolution(sol);
	return 1;
}
int soveknight(int x, int y, int movei, int sol[N][N], int xMove[N], int yMove[N])
{
	int k, next_x, next_y;
	if (movei == N * N){
		return 1;}
	for (k = 0; k < 8; k++) {
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		if (notvisited(next_x, next_y, sol)) {
			sol[next_x][next_y] = movei;
			
			if (soveknight(next_x, next_y, movei + 1, sol, xMove, yMove)== 1)
				return 1;
			else{
				sol[next_x][next_y] = -1; 
				}
		}
	}
	return 0;
}
int main()
{
  printf("This Matrix is a solution to Knight's Travail Problem:\n\n");
	solveKT();
	return 0;
}
