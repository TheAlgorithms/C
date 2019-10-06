

int myAtoi(char * str){
    int i = 0, len = strlen(str),p =0,flag =1;
    long sum = 0;
    int flagw = 0;
    char c,p1;
    for (i = 0; i <len; i++)
    {
        c = str[i];
        switch(c)
        {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0':
                flagw = 1;
                sum = sum*10 + (c-48);

                if(flag == 1 && sum > pow(2,31)-1)
                {
                        return INT_MAX;
                } else if(flag == -1 && sum > pow(2,31))
                {

                    return INT_MIN;
                }
                continue;

            case '-':
                if(flagw == 1)
                    return sum*flag;
                 p1=str[i+1];
                p = p1;
                if(p >= 48 && p <=57)
                {
                    flag = -1;
                    continue;
                }
                else
                    return 0;
                break;
            case ' ':
                if(flagw == 1)
                    return sum*flag;
                continue;
                break;
            case '+':
                if(flagw == 1)
                    return sum*flag;
                p1 = str[i+1];
                p = p1;
                if(p>=48 && p<= 57)
                {

                    flag = 1;
                    continue;
                } else{
                    return 0;
                }
                continue;
            default:
                if((c < 48 || c > 57) && flagw != 1 )
                    return 0;
                else if((c < 48 || c > 57) && flagw == 1)
                    return sum*flag;
        }
    }

    return sum*flag;
}
