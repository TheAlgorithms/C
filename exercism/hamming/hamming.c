#include "hamming.h"

/*
 The program calculates the Hamming Distance between two DNA strands represented as sequences of characters (C, A, G, and T). 
 
 The Hamming Distance is a measure of the number of differences between two DNA strands of equal length. 
 
 The program should ensure that the input sequences have the same length and then count the differing characters to determine the Hamming Distance.

 This calculation is a common task in biology and science in general.

*/

int computer(const char *lhgs, const char *rhs);

int main(void) {
    // Define two character arrays (strings) lhgs and rhs
    const char* lhgs = "GAGCCTACTAACGGGAT";
    const char* rhs = "CATCGTAATGACGGCCT";

    // Call the 'computer' function with lhgs and rhs as arguments and store the result in 'distance'
    int distance = computer(lhgs, rhs);

    printf("%d\n", distance);

    return 0;
}

int computer(const char *lhgs, const char *rhs) {
    int distance = 0;

    // Get the lengths of the input strings 'lhgs' and 'rhs'
    size_t lhsLength = strlen(lhgs);
    size_t rhsLength = strlen(rhs);

    // If the lengths of the two strings are not equal, return -1 to indicate an error
    if (lhsLength != rhsLength) {
        return -1;
    }

    // If the lengths are equal, compare the characters of 'lhgs' and 'rhs' character by character
    for (size_t index = 0; index < strlen(lhgs); index++) {
        if (lhgs[index] != rhs[index]) {
            // If the characters at the same position are different, increment the 'distance' by 1
            distance += 1;
        }
    }

    return distance;
}

