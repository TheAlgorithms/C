//recursion problem : Sudoku Solver
/*You are given an incomplete N*N Sudoku and asked to solve it using the following recursive algorithm:
(1) Scan the Sudoku from left to right row-wise to search for an empty cell.
(2) If there are no empty cells, print the Sudoku. Go to step 5.
(3) In the empty cell, try putting numbers 1 to N while ensuring that no two numbers in a single row, column, or box are same. Go back to step 1.
(4) Declare that the Sudoku is Invalid.
(5) Exit.*/

#include <stdio.h>

const int M=144;
int N, R, C;

int OKrow(int a[M], int x, int y, int v) {
	int j;
	for(j=0; j<N; j++)
		if(a[x*N+j] == v)
			return 0;
	return 1;
}
int OKcol(int a[M], int x, int y, int v) {
	int i;
	for(i=0; i<N; i++)
		if(a[i*N+y] == v)
			return 0;
	return 1;
}
int OKbox(int a[M], int x, int y, int v) {
	int bi=x/R, bj=y/C, i, j;
	for(i=0; i<R; i++)
		for(j=0; j<C; j++)
			if(a[(i + bi*R)*N + (j + bj*C)] == v)
				return 0;
	return 1;
}
int OK(int a[M], int x, int y, int v) {
	return OKrow(a,x,y,v) && OKcol(a,x,y,v) && OKbox(a,x,y,v);
}

void print(int a[M]) {
	int i, j;
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			printf("%d%c", a[i*N+j], (j==N-1 ? '\n':' '));
}

int solve(int a[M]) {
	int i, j, v, rem=0;
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			if(a[i*N+j] == 0) {
				rem = 1;
				for(v=1; v<=N; v++) {
					if(OK(a,i,j,v)) {
						a[i*N+j] = v;
						if(solve(a)) return 1;
						a[i*N+j] = 0;
					}
				}
			}
		}
	}
	if(rem == 0) return 1;
	return 0;
}

int main() {
	scanf("%d%d%d", &N, &R, &C);
	int a[M], i, j;
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			scanf("%d", &a[i*N+j]);

	if(solve(a)) print(a);
	else printf("Invalid\n");
	return 0;
}
