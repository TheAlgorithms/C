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
    testNumber=5;
    printf("The factorial of %d is %llu\n", testNumber, computeFactorial(testNumber));
    testNumber=4;
    printf("The factorial of %d is %llu\n", testNumber, computeFactorial(testNumber));
    testNumber=6;
    printf("The factorial of %d is %llu\n", testNumber, computeFactorial(testNumber));
    testNumber=7;
    printf("The factorial of %d is %llu\n", testNumber, computeFactorial(testNumber));
    testNumber=9;
    printf("The factorial of %d is %llu\n", testNumber, computeFactorial(testNumber));
    testNumber=10;
    printf("The factorial of %d is %llu\n", testNumber, computeFactorial(testNumber));
    return 0;
}
