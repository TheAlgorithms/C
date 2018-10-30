#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

typedef struct {
	int row;
	int col;
} Point;

/*int mat[N][N] =
{
    { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
    { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
    { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
    { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
    { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
    { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
    { 0, 1, 0, 0, 0, 0, 1, 0, 0, 1 },
    { 0, 1, 0, 0, 0, 1, 1, 1, 0, 1 }
};*/

int mat[N][N];
int visited[N][N] = {0};
int soln[N][N] = {0};
Point stack[N*N];
int top = -1;

int solveMaze(Point pt)
{
	int r, c, x, y, res;
	r = c = 1;

	if(pt.row == 9 && pt.col == 9)
		return 1;
	
	while(r != -2) {
		c = 1;
		while(c != -2) {
			x = pt.row + r;
			y = pt.col + c;

			if(isValid(x, y)) {
				if(mat[x][y] == 1 && visited[x][y] == 0) {
					visited[x][y] = 1;
					pt.row = x;
					pt.col = y;
					push(pt);

					res = solveMaze(pt);
					if(res)
						printSoln();
				}
			}
			c--;
		}
		r--;
	}
	pt = pop();
	res = solveMaze(pt);
	
	return 0;
}

void printSoln() {
	int soln[N][N] = {0};
	int i, j;
	printf("Solution of maze : \n\n");

	while(top != -1) {
		i = stack[top].row;
		j = stack[top].col;
		soln[i][j] = 1;
		top--;
	}
	for(i = 0; i < 10; i++) {
		for(j = 0; j < 10; j++) {
			printf("%d ", soln[i][j]);
		}
		printf("\n");
	}
	exit(0);
}

int isValid(int r, int c) {
	if(r >= 0 && c >= 0 && r <= 9 && c <= 9)
		return 1;
	else
		return 0;
}

void push(Point pt) {
	top++;
	if(top != 100) {
		stack[top] = pt;
	}
	else {
		printf("Solution does not exist.\n");
		exit(0);
	}
}

Point pop() {
	Point p;
	if(top != -1) {
		top--;
		p = stack[top];
	}
	else {
		printf("Solution does not exist.\n");
		exit(0);
	}
	return p;
}

int main() {
    int i, j;
    Point start;
    
    srand(time(NULL));
    printf("MAZE : \n\n");
    for(i = 0; i < N; i++) {
    	for(j = 0; j < N; j++) {
    		mat[i][j] = rand() % 2;
	}
    }
    
    mat[0][0] = mat[9][9] = 1;
    
    for(i = 0; i < N; i++) {
    	for(j = 0; j < N; j++) {
    		printf("%d ", mat[i][j]);
	}
		printf("\n");
    }
    
    printf("\n\n");
    
    start.row = start.col = 0;
    
    push(start);
    
    if(!solveMaze(start))
    	printf("Solution does not exist.\n");
    return 0;
}
