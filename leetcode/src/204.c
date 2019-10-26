int countPrimes(int n){
    int count = 0;
    int isPrime;
    for (int i = 2; i <= n; i++){
        isPrime = 1;
        for(int j = 2; j < i; j++){
            if(i % j == 0){
                isPrime = 0;
            }
        }
        if(isPrime == 1){
            count++;
        }   
    } 
    return count;
}