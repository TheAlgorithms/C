/*
	Author: Luca Palumbo
	Date: 	9.10.2019
*/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

//Function usage that print how to use the program.
void usage(char* name){
	printf("\nUsage: %s <text>\n", name);
	printf("Use this command to both encrypt and decrypt\n\n");
}

//Defining function rot13. It both encrypt and decrypt.
void rot13(char* text);

int main(int argc, char *argv[]){
	int opt;
	if (argc != 2){
		usage( argv[0] );
		return -1;
	}
	rot13(argv[1]);
	return 1;
}

/*
Rot13 is a cipher method similar to Caesar Cipher, but it use 13 as key.
It is less strong than Caesar becouse the encryption key is the same as
the decryption.
*/
void rot13(char* text){
	int i;
	for(i=0;text[i]!='\0';i++){
		text[i] = toupper(text[i]);
		if ( isalpha( text[i] ) ){
			text[i]+=13;
			if ( text[i] > 'Z'){
				text[i] = 'A'-1+text[i]-'Z';
			}
		}
	}
	printf("%s\n", text);
	return ;
}
