int romanToInt(char * s){
    int romanToInt = 0;
    for (int i = 0; i < strlen(s); i++) {
        switch(s[i]) {
            case 'I':
                if (i+1 < strlen(s)) {
                    if (s[i + 1] == 'V' || s[i + 1] == 'X') {
                        romanToInt -= 1;
                        break;
                    }
                }
                romanToInt += 1;
                break;
            case 'V':
                romanToInt += 5;
                break;
            case 'X':
                if (i+1 < strlen(s)) {
                    if (s[i + 1] == 'L' || s[i + 1] == 'C') {
                        romanToInt -= 10;
                        break;
                    }
                }
                romanToInt += 10;
                break;
            case 'L':
                romanToInt += 50;
                break;
            case 'C':
                if (i+1 < strlen(s)) {
                    if (s[i + 1] == 'D' || s[i + 1] == 'M') {
                        romanToInt -= 100;
                        break;
                    }
                }
                romanToInt += 100;
                break;
            case 'D':
                romanToInt += 500;
                break;
            case 'M':
                romanToInt += 1000;
                break;
            default:
                break;
        }
    }
    return romanToInt;
}