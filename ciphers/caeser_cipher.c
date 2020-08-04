/**
 * @file
 * @brief: caeser cipher is the one of the basic cipher in cryptography
 * @details: it is encoded by shifting each letter to the forward and 
 * backward to make it encrypted
 * \author [Rishabh Patel](https://github.com/Rishabhpatel803)
 */

#include <stdio.h>

/*
* Encrypt function encrypts the message to the required one
*/
void encrypt() {
  char msg[100], ch;//msg is used to store the message
  int i, key;
  printf("Enter a plaintext : ");
  scanf("%s", &*msg);//Inputting of message
  printf("\nEnter key : ");
  scanf("%d", &key);//Inoutting key
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
  printf("\nPress Enter to continue....");
}

/*
* Decrypt function encrypts the message to the required one
*/
void decrypt() {
  char msg[100], ch;//msg is for storing message
  int i, key;
  printf("Enter a Encrypted message : ");
  scanf("%s", &*msg);//reading enccypted message
  printf("\nEnter key : ");
  scanf("%d", &key);//reading key
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
int main() {
  int choice;
  while (1) {
    //Giving user choice that he wants to encrypt or decrypt
    printf("Enter \n 1.Encrytpion\n 2.Decryption");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    if (choice == 1) {
      encrypt();
    } else if (choice == 2) {
      decrypt();
    }
    /*else if(choice==3){
    exit(0);}*/
    else {
      printf("\nWrong choice! Enter again");
    }
  }
  return 0;
}
