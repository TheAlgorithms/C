#include <stdio.h>

// returns Decimal value for respective Roman Numeral
int getVal(char x) {
    int val;
    
    switch (x) {
        case 'I' :  val = 1;    break;
        case 'V' :  val = 5;    break;
        case 'X' :  val = 10;   break;
        case 'L' :  val = 50;   break;
        case 'C' :  val = 100;  break;
        case 'D' :  val = 500;  break;
        case 'M' :  val = 1000; break;
    }
    
    return val;
}

// converts Roman Number to Decimal Number
int romanToInt(char *s){
    int res = 0;
    
    // store length of Roman Number
    int len = 0;
    for (len = 0; s[len] != '\0'; len++);

    // iterate until second last numeral
    for (int i = 0; i < len - 1; i++) {
        int val = getVal(s[i]);
        int nxt = getVal(s[i + 1]);
        
        // subtract current numeral's value if
        // following numeral's value is larger
        // else add current numeral's value to
        // resultant
        if (val < nxt)  res -= val;
        else            res += val;
    }

    // add last numeral's value to resultant
    res += getVal(s[len - 1]);
    
    return res;
}


// Driver Program
int main() {
    printf("Enter Roman Number:\t");
    char s[64]; scanf("%s", s);

    printf("Number in Decimal:\t");
	printf("%d\n", romanToInt(s));
	
	return 0;
}