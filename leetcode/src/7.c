int reverse(int x){
 int res=0;
    
    int s=1;
    if(x > INT_MAX || x<(-INT_MAX)){
        return 0;
    }
    if(x<0){
        s=-1;
        x*=-1;
    }
    while(x!=0){
        if(res > INT_MAX/10){
             return 0;
        }
        res=(res*10)+(x%10);
        x/=10;
     }
    return (s*res);
}
