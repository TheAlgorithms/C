int commonFactors(int a, int b){
    int min=a>b?b:a;
    int count=0;
    for(int i=1;i<=a;i++)
    {
        if(a%i==0&&b%i==0)
            count++;
    }
    return count;
}
