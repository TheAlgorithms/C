/**
 * @file
 * @author [serturx](https://github.com/serturx/)
 * @brief Encode a null terminated string using [Run-length encoding](https://en.wikipedia.org/wiki/Run-length_encoding)
 * @details
 * Run-length encoding is a lossless compression algorithm.
 * It works by counting the consecutive occurences symbols
 * and encodes that series of consecutive symbols into the
 * counted symbol and a number denoting the number of
 * consecutive occorences.
 * 
 * For example the string "AAAABBCCD" gets encoded into "4A2B2C1D"
 * 
 */

#include <stdio.h>  /// for IO operations
#include <string.h> /// for string functions
#include <stdlib.h> /// for malloc/free
#include <assert.h> /// for assert

/**
 * @brief Encodes a null-terminated string using run-length encoding
 * @param str String to encode
 * @return char* Encoded string
 */

char* run_length_encode(char* str) {
    int str_length = strlen(str);
    int encoded_index = 0;

    //allocate space for worst-case scenario
    char* encoded = malloc(2 * strlen(str));
    
    //temp space for int to str conversion
    char int_str[20];

    for(int i = 0; i < str_length; ++i) {
        int count = 0;
        char current = str[i];

        //count occurences
        while(current == str[i + count]) count++;

        i += count - 1;

        //convert occurrence amount to string and write to encoded string
        sprintf(int_str, "%d", count);
        int int_str_length = strlen(int_str);
        strncpy(&encoded[encoded_index], int_str, strlen(int_str));

        //write current char to encoded string
        encoded_index += strlen(int_str);
        encoded[encoded_index] = current;
        ++encoded_index;
    }

    //null terminate string and move encoded string to compacted memory space 
    encoded[encoded_index] = '\0';
    char* compacted_string = malloc(strlen(encoded) + 1);
    strcpy(compacted_string, encoded);
    
    free(encoded);

    return compacted_string;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
    char* test;
    test = run_length_encode("aaaaaaabbbaaccccdefaadr");
    assert(!strcmp(test, "7a3b2a4c1d1e1f2a1d1r"));
    free(test);
    test = run_length_encode("lidjhvipdurevbeirbgipeahapoeuhwaipefupwieofb");
    assert(!strcmp(test, "1l1i1d1j1h1v1i1p1d1u1r1e1v1b1e1i1r1b1g1i1p1e1a1h1a1p1o1e1u1h1w1a1i1p1e1f1u1p1w1i1e1o1f1bq"));
    free(test);
    test = run_length_encode("htuuuurwuquququuuaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaahghghrw");
    assert(!strcmp(test, "1h1t4u1r1w1u1q1u1q1u1q3u76a1h1g1h1g1h1r1w"));
    free(test);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test();  // run self-test implementations
    printf("All tests have passed!\n");
    return 0;
}
