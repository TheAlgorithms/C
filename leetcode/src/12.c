char *getOne(char c){
    switch (c) {
        case '9':
            return "IX";

        case '8':
            return "VIII";

        case '7':
            return "VII";

        case '6':
            return "VI";

        case '5':
            return "V";

        case '4':
            return "IV";

        case '3':
            return "III";

        case '2':
            return "II";            

        case '1':
            return "I";

        case '0':
            return "";

        default:
            return NULL;
    }
}

char *getTen(char c){
    switch (c) {
        case '9':
            return "XC";

        case '8':
            return "LXXX";

        case '7':
            return "LXX";

        case '6':
            return "LX";

        case '5':
            return "L";

        case '4':
            return "XL";

        case '3':
            return "XXX";

        case '2':
            return "XX";            

        case '1':
            return "X";

        case '0':
            return "";

        default:
            return NULL;
    }

}

char *getHundred(char c){
    switch (c) {
        case '9':
            return "CM";

        case '8':
            return "DCCC";

        case '7':
            return "DCC";

        case '6':
            return "DC";

        case '5':
            return "D";

        case '4':
            return "CD";

        case '3':
            return "CCC";

        case '2':
            return "CC";            

        case '1':
            return "C";

        case '0':
            return "";
            
        default:
            return NULL;
    }
}

char *getThousand(char c){
    switch (c) {
        case '3':
            return "MMM";

        case '2':
            return "MM";            

        case '1':
            return "M";
            
        default:
            return NULL;
    }
}




char * intToRoman(int num){
    int length;
    char number[5];
    char *s = malloc(16*sizeof(char));
    
    sprintf(number, "%i", num); 
    
    length = strlen(number);

    switch (length){
        case 4:
            sprintf(s,"%s%s%s%s", getThousand(number[0]), getHundred(number[1]), getTen(number[2]), getOne(number[3]));
            break;

        case 3:
            sprintf(s,"%s%s%s", getHundred(number[0]), getTen(number[1]), getOne(number[2]));
            
            break;

        case 2:
            sprintf(s,"%s%s", getTen(number[0]), getOne(number[1]));
            
            break;

        case 1: 
            s = getOne(number[0]);
            break;

        default:
            break;
    }
    return s;
}
