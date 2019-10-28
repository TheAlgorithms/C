int myAtoi(char * str){
    int minusFlag = 0;
    int length = strlen(str);
    long int result = 0;
    char numberBuffer[11];
    int counter = 0;
    while(str[counter] == ' '){
        counter++;
    }
    str = &str[counter];
    counter = 0;

   
    for(int i=0; i<length; i++){
        if(i == 0) {
            if(str[0] == '-'){
                minusFlag = 1;
                i++;
            } else if(str[0] == '+'){
                i++;
            }
        }
        if(counter>10){
            if(minusFlag){
                return __INT_MAX__*-1-1;
            } else {
                return __INT_MAX__;
            }
        }

        if(str[i] < '0' || str[i] > '9'){
            break;
        }
        if(counter == 0 && str[i] == '0'){
            continue;
        }
        
        numberBuffer[counter]= str[i];
        counter++;
    }

    int i = 0;
    while(counter > 0) {
        if(minusFlag){
            result -= (numberBuffer[i] - '0')*pow(10.0, counter-1);
        }else{
            result += (numberBuffer[i] - '0')*pow(10.0, counter-1);
        }
        i++;
        counter--;
    }
    
    if(result > __INT_MAX__){
        return __INT_MAX__;
    } else if(result < __INT_MAX__*-1-1){
        return __INT_MAX__*-1-1;
    }
    return result;
}

