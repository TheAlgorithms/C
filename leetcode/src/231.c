bool isPowerOfTwo(int n){
    if (! n) return false;
    while (n % 2 == 0) n /= 2;
    return n == 1;
}