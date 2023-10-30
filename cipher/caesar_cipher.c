/**
 * @file
 * @brief An [caesar cipher](https://en.wikipedia.org/wiki/Caesar_cipher) is a
 * letter substitution cipher that uses linear shift to substitute
 * letters in a message. It is one of the simplest cipher with only 26
 * possible keys.
 * @details Given an alphabet of length M with characters with numeric values
 * 0-(M-1), an arbitrary character x can be transformed with the expression (x
 * + b) % M into our ciphertext character.
 * @author [Tuchar Chandra Das](https://github.com/Thunder-Ultra)
 */

#include <assert.h>  // For making Assertions
#include <stdio.h>   // For standard input/Output
#include <stdlib.h>  // For dynamic memory management
#include <string.h>  // For finding the length of a string

/**
 * @brief Encrypts a given message
 *
 * @param msg raw message
 * @param key Key used to Encrypt the message
 *
 * @returns char*
 */
char* encrypt(const char* msg, int key)
{
    int i;
    char* result = (char*)malloc(
        strlen(msg));  // Create a string to store the encrypted string

    for (i = 0; i < strlen(msg); i++)
    {
        if (msg[i] >= 'a' && msg[i] <= 'z')
        {
            result[i] = 'a' + (msg[i] - 'a' + key) % 26;
        }
        else if (msg[i] >= 'A' && msg[i] <= 'Z')
        {
            result[i] = 'A' + (msg[i] - 'A' + key) % 26;
        }
        else
        {
            result[i] = msg[i];
        }
    }

    return result;
}

/**
 * @brief Decrypts a given message
 *
 * @param msg raw message
 * @param key Key to Use to Decrypt the message
 *
 * returns char*
 */
char* decrypt(const char* msg, int key)
{
    int i;
    char* result = (char*)malloc(
        strlen(msg));  // Create string to hold the Decrypted string

    for (i = 0; i < strlen(msg); i++)
    {
        if (msg[i] >= 'a' && msg[i] <= 'z')
        {
            result[i] = 'a' + (msg[i] - 'a' - key + 26) % 26;
        }
        else if (msg[i] >= 'A' && msg[i] <= 'Z')
        {
            result[i] = 'A' + (msg[i] - 'A' - key + 26) % 26;
        }
        else
        {
            result[i] = msg[i];
        }
    }

    return result;
}

/**
 * @brief Tests a given string
 *
 * @param msg Raw text
 * @param cipher Encrypted text
 * @param key The key used to encrypt/decrypt
 *
 * @returns void
 */
void test_string(const char* msg, const char* cipher, int key)
{
    // assert that the encryption worked
    assert(strcmp(encrypt(msg, key), cipher) == 0);
    // assert that we got the same string we started with
    assert(strcmp(msg, decrypt(cipher, key)) == 0);
}

/**
 * @brief Test multiple strings
 *
 * @returns void
 */
static void tests()
{
    test_string("Hello World!", "Olssv Dvysk!", 7);
    test_string("TheAlgorithms", "DroKvqybsdrwc", 10);
    test_string("I Like Coding in C , But Coding is Python is another level",
                "S Vsuo Mynsxq sx M , Led Mynsxq sc Zidryx sc kxydrob vofov",
                10);
    printf("All tests have successfully passed!\n");
}

/**
 * @brief Runs many test cases
 *
 * @returns int
 */
int main()
{
    tests();
    return 0;
}
