/**
 * A small programm where you need to guess the computer number between 1-100.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    while (1) {
        printf("Guess my number between 1-100: ");
        int number;
        int r = rand() % 100 + 1;

        while(1){
            scanf("%d", &number);
            if (number == r) {
                printf("Correct number! You guessed it.\n");
                break;
            } else if(number>r){
                printf("Number is to high. Try again.\n");
            }else{
                printf("Number is to low. Try again.\n");
            }
        }
    }

    return 0;
}
