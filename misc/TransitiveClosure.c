#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 20
int mat[N][N];
int res[N][N];

void printres(int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
}

void transitiveClosure(int n){
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            res[i][j] = mat[i][j];
    
    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                res[i][j] = res[i][j] || (res[i][k] && res[k][j]);
            }
        }
    }
    printres(n);
}

int main(){
    int n;
    printf("Enter vertices: \n");
    scanf("%d", &n);
    printf("Enter Adj Matrix: \n");
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            scanf("%d", &mat[i][j]);
    
    transitiveClosure(n);
}