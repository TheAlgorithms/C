#include "hamming.h"

// Declare a function prototype for the 'computer' function
int computer(const char *lhgs, const char *rhs);

// The main function, where the program execution starts
int main(void) {
    // Define two character arrays (strings) lhgs and rhs
    const char* lhgs = "GAGCCTACTAACGGGAT";
    const char* rhs = "CATCGTAATGACGGCCT";

    // Call the 'computer' function with lhgs and rhs as arguments and store the result in 'distance'
    int distance = computer(lhgs, rhs);

    // Print the value of 'distance' to the console
    printf("%d\n", distance);

    // Return 0 to indicate successful execution to the operating system
    return 0;
}

// Definition of the 'computer' function
int computer(const char *lhgs, const char *rhs) {
    // Initialize a variable 'distance' to 0 to keep track of the differences between the two strings
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

    // Return the 'distance' value, which represents the number of differing characters
    return distance;
}

