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

#include <stdio.h>   // For standard input/Output
#include <stdlib.h>  // For dynamic memory management
#include <string.h>  // For finding the length of a string

/**
 * @brief Encrypts a given message
 * @param msg raw message
 * @param
 */
char* encrypt(char* msg, int key)
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
 * @param msg raw message
 * @param
 */
char* decrypt(char* msg, int key)
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
 * @brief Test a sample string and prints the Raw, Encrypted, and
 * Unencrypted Message
 *
 * @returns void
 */
void main()
{
    // Some code to sample to check the working of the algorithm
    char message[] = "Hello, World!";
    printf("Raw Message: %s\n", message);
    // Here goes the key with which to encrypt the message
    int key = 7;

    char* encrypted_message = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_message);

    char* decrypted_message = decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n", decrypted_message);

    free(encrypted_message);
    free(decrypted_message);
}
