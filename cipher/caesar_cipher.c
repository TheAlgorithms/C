#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a message using the Caesar Cipher
char* encrypt(char* message, int key)
{
    int i;
    char* result = (char*)malloc(strlen(message) + 1);

    for (i = 0; i < strlen(message); i++)
    {
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            result[i] = 'a' + (message[i] - 'a' + key) % 26;
        }
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            result[i] = 'A' + (message[i] - 'A' + key) % 26;
        }
        else
        {
            result[i] = message[i];
        }
    }

    result[i] = '\0';
    return result;
}

// Function to decrypt a message using the Caesar Cipher
char* decrypt(char* message, int key)
{
    int i;
    char* result = (char*)malloc(strlen(message) + 1);

    for (i = 0; i < strlen(message); i++)
    {
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            result[i] = 'a' + (message[i] - 'a' - key + 26) % 26;
        }
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            result[i] = 'A' + (message[i] - 'A' - key + 26) % 26;
        }
        else
        {
            result[i] = message[i];
        }
    }

    result[i] = '\0';
    return result;
}

int main()
{
    char message[] = "Hello, World!";
    int key = 3;

    char* encrypted_message = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_message);

    char* decrypted_message = decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n", decrypted_message);

    free(encrypted_message);
    free(decrypted_message);

    return 0;
}
