#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_VALUE 65535

char *encode_decode();
int usage(void);    

char result[MAX_VALUE] = "";
char text[1024];
char letter;

int main(int argc, char *argv[]){

    if (argc != 2){
        printf("ERROR\n");
        usage();
    }
    else{
        if(strcmp(argv[1], "-e") == 0){
            printf("Enter the Msg to encode: ");
            scanf("%[^\n]%*c", text);
            encode_decode(text);
        }
        else if(strcmp(argv[1], "-d") == 0){
            printf("Enter the Msg to decode: ");
            fgets(text, MAX_VALUE, stdin);
            encode_decode(text);
        }
        else{
            printf("ERROR\n");
            usage();
        }
    }
}
int usage(void){
    printf("Usage:\n-e : Encoding a Message\n-d : Decoding a Message\n(example)\n./rot13 -e\n./rot13 -d\n");
}

char *encode_decode(char text[]){

    for (int i = 0; i <= strlen(text); i++){

        //simple addition
        if (text[i] >= 97 && text[i] <= 109){
            letter = text[i] + 13;
            strncat(result, &letter, 1);
        }

        //capital addition
        else if (text[i] >= 65 && text[i] <= 77){
            letter = text[i] + 13;
            strncat(result, &letter, 1);
        }

        //simple subtraction
        else if (text[i] >= 110 && text[i] <= 122){
            letter = text[i] - 13;
            strncat(result, &letter, 1);
        }

        //capital substraction
        else if (text[i] >= 78 && text[i] <= 90){
            letter = text[i] - 13;
            strncat(result, &letter, 1);
        }

        //other characters
        //space    
        else if(text[i] == 32){
            letter = text[i] - 0;
            strncat(result, &letter, 1);
        }

        //numbers and symbols //59
        else if(text[i] >= 33 && text[i] <= 64){
            letter = text[i] - 0;
            strncat(result, &letter, 1);
        }

        //symbols
        else if(text[i] >= 123 && text[i] <= 126){
            letter = text[i] - 0;
            strncat(result, &letter, 1);
        }
    }
    printf("\nOutput:\n\n%s\n", result);
    return "%s", result;
}
/*
Project name : ROT13 Cipher
Author : J.M.V.R.P
Date : 03/05/2022
Language : C
*/