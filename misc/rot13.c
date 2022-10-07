/**
 * @file rot13.c
 * @brief ROT13 is a simple letter substitution cipher that replaces a
 * letter with the 13th letter after it in the alphabet.
 * https://en.wikipedia.org/wiki/ROT13
 * @details
 * @author [Jeremias Moreira Gomes](https://github.com/j3r3mias)
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>

/**
 * @brief Apply the ROT13 cipher
 * @param s contains the string to be processed
 */
void rot13(char *s) {
    for (int i = 0; s[i]; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = 'A' + ((s[i] - 'A' + 13) % 26);
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = 'a' + ((s[i] - 'a' + 13) % 26);
        }
    } 
}

void test() {
    char test_01[] = "The more I C, the less I see.";
    rot13(test_01);
    assert(strcmp(test_01, "Gur zber V P, gur yrff V frr.") == 0);

    char test_02[] = "Which witch switched the Swiss wristwatches?";
    rot13(test_02);
    assert(strcmp(test_02, "Juvpu jvgpu fjvgpurq gur Fjvff jevfgjngpurf?") == 0);

    char test_03[] = "Juvpu jvgpu fjvgpurq gur Fjvff jevfgjngpurf?";
    rot13(test_03);
    assert(strcmp(test_03, "Which witch switched the Swiss wristwatches?") == 0);

    printf("All tests have successfully passed!\n");
}


int main() {
    test();
    return 0;
}
