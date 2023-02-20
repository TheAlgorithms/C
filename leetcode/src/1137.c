// Dynamic Programming
// Runtime: O(n)
// Space: O(1)
int tribonacci(int n){
    int t0 = 0;
    int t1 = 1;
    int t2 = 1;

    if (n == 0) {
        return t0;
    }

    if (n == 1){
        return t1;
    }

    if (n == 2){
        return t2;
    }

    for (int i = 0; i < n - 2; i++){
        int nextT = t0 + t1 + t2;
        t0 = t1;
        t1 = t2;
        t2 = nextT;
    }

    return t2;
}
