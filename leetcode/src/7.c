int reverse(int x) {
    int dig = 0;
    int num = 0;
    
     while(x != 0) {
        dig = x %  10;
        x /= 10;
        
        if(num > INT_MAX / 10 || num == INT_MAX / 10 && dig > 7) return 0;
        if(num < INT_MIN / 10 || num == INT_MIN / 10 && dig < -8) return 0;
        
        num = (num * 10) + dig;
    }

    return num;
}

