#include <stdio.h>

#define MAX_LIMIT 200 

unsigned long long factResults[MAX_LIMIT] = {0};

unsigned long long computeFactorial(int sequenceNumber) {
    if (sequenceNumber == 0) {
        return 1;
    }
    if (factResults[sequenceNumber] != 0) {
        return factResults[sequenceNumber];
    }
    factResults[sequenceNumber] = sequenceNumber * computeFactorial(sequenceNumber - 1);
    return factResults[sequenceNumber];
}

int main() {
    int testNumber;
    printf("Enter a number: ");
    scanf("%d", &testNumber);
    if (testNumber < 0 || testNumber >= MAX_LIMIT) {
        printf("Invalid input! Please enter a non-negative number less than %d.\n", MAX_LIMIT);
        return 1;
    }
    printf("The factorial of %d is %llu\n", testNumber, computeFactorial(testNumber));
    return 0;
}
