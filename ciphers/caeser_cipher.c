// Code by Rishabh Patel

#include <stdio.h>

void encrypt() {
  char msg[100], ch;
  int i, key;
  printf("Enter a plaintext : ");
  scanf("%s", &*msg);
  printf("\nEnter key : ");
  scanf("%d", &key);
  for (i = 0; msg[i] != '\0'; i++) {
    ch = msg[i];
    if (ch >= 'a' && ch <= 'z') {
      ch = ch + key;
      if (ch > 'z') {
        ch = ch - 'z' + 'a' - 1;
      }
      msg[i] = ch;
    } else if (ch >= 'A' && ch < 'Z') {
      ch = ch + key;
      if (ch > 'Z') {
        ch = ch - 'Z' + 'A' - 1;
      }
      msg[i] = ch;
    }
  }
  printf("\nEncrypted message: %s", msg);
  printf("\nPress Enter to continue....");
}

void decrypt() {
  char msg[100], ch;
  int i, key;
  printf("Enter a Encrypted message : ");
  scanf("%s", &*msg);
  printf("\nEnter key : ");
  scanf("%d", &key);
  for (i = 0; msg[i] != '\0'; i++) {
    ch = msg[i];
    if (ch >= 'a' && ch <= 'z') {
      ch = ch - key;
      if (ch < 'a') {
        ch = ch + 'z' - 'a' + 1;
      }
      msg[i] = ch;
    } else if (ch >= 'A' && ch < 'Z') {
      ch = ch + key;
      if (ch < 'A') {
        ch = ch + 'Z' - 'A' + 1;
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
