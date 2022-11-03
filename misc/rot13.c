/**
 * @file
 * @brief [ROT13](https://en.wikipedia.org/wiki/ROT13) is a simple letter 
 * substitution cipher that replaces a letter with the 13th letter after it in 
 * the alphabet.
 * @details ROT13 transforms a piece of text by examining its alphabetic
 * characters and replacing each one with the letter 13 places further along in
 * the alphabet, wrapping back to the beginning if necessary. A becomes N, B
 * becomes O, and so on up to M, which becomes Z, then the sequence continues at
 * the beginning of the alphabet: N becomes A, O becomes B, and so on to Z,
 * which becomes M.
 * @author [Jeremias Moreira Gomes](https://github.com/j3r3mias)
 */

#include <stdio.h>     /// for IO operations
#include <string.h>    /// for string operations
#include <assert.h>    /// for assert

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

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
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

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test();  // run self-test implementations
    return 0;
}
