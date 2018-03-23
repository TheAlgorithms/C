// Recursion problem
//Given the denominations of currencies available in a system, find the number of ways an ATM machine can
//generate notes for an entered amount N.

#include <stdio.h>

int ways(int n, int a[], int k) {
    if(n<0 || k<0) return 0;
    if(n == 0) return 1;
    if(k == 0) return 0;
    return ways(n, a, k-1) + ways(n-a[k-1], a, k);
}

int main() {
    int m; scanf("%d", &m);
    int coin[m], i; for(i=0; i<m; i++) scanf("%d", &coin[i]);

    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        printf("%d\n", ways(n, coin, m));
    }
    return 0;
}
