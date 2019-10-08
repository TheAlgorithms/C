#include<stdio.h>

int main() {

    int input, tmp, numPlace = 1, k, sum = 0, unit, res;

    printf("Enter a decimal number: \n");
    scanf("%d", &input);

    if(input <= 0) {
        printf("Input must > 0\n");
        return -1;
    }
    else if(input < 10) {
        printf("%d is an armstrong number!\n", input);
        return 0;
    }

    tmp = input;
    while(1) {
        tmp /= 10;
        if(tmp != 0) {
            numPlace++;
        }
        else {
            break;
        }
    }

    tmp = input;
    while(tmp > 0) {
        unit = tmp % 10;
        res = 1;
        for(k = 0; k < numPlace; k++) {
            res *= unit;
        }
        sum += res;
        tmp /= 10;
    }

    if(sum == input) {
        printf("%d is an armstrong number!\n", input);
    }
    else {
        printf("%d is not an armstrong number!\n", input);
    }

    return 0;
}
