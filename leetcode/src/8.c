int myAtoi(char* str) {
    int val = 0;
    int i = 0;
    int len = 0;
    int dig = 0;
    int neg_flag = 0;
    
    len = strlen(str);
    if(!len)
        return val;
    
    /* Get rid of whitespaces */
    for(i = 0; i < len && str[i] == ' '; i++);
    
    if(str[i] == '-') {
        neg_flag = 1;
        i++;
    } else if(str[i] == '+') {
        i++;
    }
    
    for(; str[i] >= '0' && str[i] <= '9'; i++) {
        dig = str[i] - '0';
        if(val > INT_MAX / 10 || val == INT_MAX / 10 && dig > 7)
            return neg_flag ? INT_MIN : INT_MAX;
        
        val = (val * 10) + dig;
    }
    
    return neg_flag ? (-1 * val) : val;
}

