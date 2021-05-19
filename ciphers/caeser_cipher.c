/**
 * @file
 * @brief: caeser cipher is the one of the basic cipher in cryptography
 * @details: it is encoded by shifting each letter to the forward and 
 * backward to make it encrypted
 * \author [Rishabh Patel](https://github.com/Rishabhpatel803)
 */

#include <stdio.h>

void decrypt(char *msg, int key);
/*
 * Encrypt function encrypts the message to the required one
 */
void encrypt(char *msg,int key) {
  char ch;//msg is used to store the message
  int i;
  for (i = 0; msg[i] != '\0'; i++) {
    ch = msg[i];
    if (ch >= 'a' && ch <= 'z') {
      ch = ch + key;
      if (ch > 'z') {
        ch = ch - 'z' + 'a' - 1;//doing encryption of lower case letters
      }
      msg[i] = ch;
    } else if (ch >= 'A' && ch < 'Z') {
      ch = ch + key;
      if (ch > 'Z') {
        ch = ch - 'Z' + 'A' - 1;//doing encryption of upper case letters
      }
      msg[i] = ch;
    }
  }
  printf("\nEncrypted message: %s", msg);
  decrypt(msg, key);
  printf("\nPress Enter to continue....");
}

/*
* Decrypt function encrypts the message to the required one
*/
void decrypt(char *msg,int key) {
  char ch;//msg is for storing message
  int i;
  for (i = 0; msg[i] != '\0'; i++) {
    ch = msg[i];
    if (ch >= 'a' && ch <= 'z') {
      ch = ch - key;
      if (ch < 'a') {
        ch = ch + 'z' - 'a' + 1;//decryption of lower case letter
      }
      msg[i] = ch;
    } else if (ch >= 'A' && ch < 'Z') {
      ch = ch + key;
      if (ch < 'A') {
        ch = ch + 'Z' - 'A' + 1;//decryption of upper case letter
      }
      msg[i] = ch;
    }
  }
  printf("\nDycrypted message: %s", msg);
  printf("\nPress Enter to continue....");
}

/*
    Test cases for testing the program
*/
void test() 
{
    char msg[] = "Grofers";
    printf("First Texst case");
    encrypt(msg, 5);
    char msg1[] = "lalaland";
    printf("Second Test Case");
    encrypt(msg1, 15);
}
int main() {
    test();
    return 0;
}
