#include <stdio.h>

// Function for Tower of Hanoi algorithm
void TOH(int n, int A, int B, int C){
    if(n>0){
        // n-1 disks in the tower
        TOH(n-1,A,C,B);
        printf("Moving disc from rod %d to %d\n",A,C);
        TOH(n-1,B,A,C);
    }
}

int main(){
    TOH(3,1,2,3);
}
