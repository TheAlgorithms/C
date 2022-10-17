

int commonFactors(int a, int b){

    int n = fmax(fmin(a,b),fmax(a,b)/2),count=0;  
    for(int i=1;i<=n;i++){
        if(a%i == 0 && b%i==0){
            count++;
        }
    }
    return count;
}
