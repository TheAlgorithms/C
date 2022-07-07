#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_VALUE 65536

char *caeser_encrypt();
char *usage();
char *caeser_decrypt();

char text[MAX_VALUE];
char result[MAX_VALUE];
int key;
char character;

int main(int argc, char *argv[]){

    if (argc != 2 ){
        printf("Error\n");
        usage();
    }
    else{
        if (strcmp(argv[1], "-c") == 0)
        {
            printf("Enter the text: ");
            fgets(text, MAX_VALUE, stdin);
            printf("Key: ");
            scanf("%d", &key);
            caeser_encrypt(text, key);
        }
        
        else if(strcmp(argv[1], "-d") == 0){
            printf("Enter the text: ");
            fgets(text, MAX_VALUE, stdin);
            caeser_encrypt(text, 3);
        }
        else if(strcmp(argv[1], "-cd_code") == 0){
            printf("Enter the text: ");
            fgets(text, MAX_VALUE, stdin);
            caeser_encrypt(text, 1);
        }
        else if(strcmp(argv[1], "-jail") == 0){
            printf("Enter the text: ");
            fgets(text, MAX_VALUE, stdin);
            caeser_encrypt(text, 2);
        }
        else if(strcmp(argv[1], "-ellen") == 0){
            printf("Enter the text: ");
            fgets(text, MAX_VALUE, stdin);
            caeser_encrypt(text, 2);
        }
        else if(strcmp(argv[1], "-cutie") == 0){
            printf("Enter the text: ");
            fgets(text, MAX_VALUE, stdin);
            caeser_encrypt(text, 3);
        }
        else if(strcmp(argv[1], "eiffel") == 0){
            printf("Enter the text: ");
            fgets(text, MAX_VALUE, stdin);
            caeser_encrypt(text, 6);
        }
        else if(strcmp(argv[1], "-wc_code") == 0){
            printf("Enter the text: ");
            fgets(text, MAX_VALUE, stdin);
            caeser_encrypt(text, 6);
        }
        else if(strcmp(argv[1], "-empty") == 0){
            printf("Enter the text: ");
            fgets(text, MAX_VALUE, stdin);
            caeser_encrypt(text, 7);
        }
        else if(strcmp(argv[1], "-baden_powell") == 0){
            printf("Enter the text: ");
            fgets(text, MAX_VALUE, stdin);
            caeser_encrypt(text, 14);
        }
        else if(strcmp(argv[1], "-any") == 0){
            printf("Enter the text: ");
            fgets(text, MAX_VALUE, stdin);
            caeser_encrypt(text, 17);
        }
        else if(strcmp(argv[1], "-see_you") == 0){
            printf("Enter the text: ");
            fgets(text, MAX_VALUE, stdin);
            caeser_encrypt(text, 18);
        }
        else if(strcmp(argv[1], "-i_see") == 0){
            printf("Enter the text: ");
            fgets(text, MAX_VALUE, stdin);
            caeser_encrypt(text, 20);
        }
        else if(strcmp(argv[1], "-easy") == 0){
            printf("Enter the text: ");
            fgets(text, MAX_VALUE, stdin);
            caeser_encrypt(text, 21);
        }
        else if(strcmp(argv[1], "-h") == 0){
            printf("Help!!");
            usage();
        }
        else{
            printf("ERROR\n");
            usage();
        }
    }
    return 0;
}

char *usage(){
    printf("Usage:\n");
    printf("-c : Custom key\n");
    printf("-d : default (the shift by 3)\n");
    printf("-h : help\n");
    printf("Caesar Varients\n");
    printf("    -cd_code        : CD code (the shift is 1)\n");
    printf("    -jail           : Jail (the shift is 2)   \n"); 
    printf("    -ellen          : Ellen (the shift is 2)\n");
    printf("    -cutie          : Cutie (the shift is 3)\n");
    printf("    -eiffel         : Eiffel (the shift is 6)\n");
    printf("    -wc_code        : WC code (the shift is 6)\n");
    printf("    -empty          : Empty (the shift is 7)\n");
    printf("    -baden_powell   : Baden Powell (the shift is 14)\n");
    printf("    -any            : Any (the shift is 17)\n");
    printf("    -see_you        : See You (the shift is 18\n");
    printf("    -i_see          : I_See (the shift is 20)\n");
    printf("    -easy           : Easy (the shift is 21)\n");
    printf("examples:\n");
    printf("    ./caeser -c\n");
    printf("    ./caeser -d\n");
    printf("    ./caeser -ellen\n");
    printf("    ./caeser -easy\n");
}

char *caeser_encrypt(char str[], int key){

    for (int i = 0; i <= strlen(text); i++)
    {
        character = text[i];

        //For Simple Letters
        if (character >= 'a' && character <= 'z')
        {
            character = character + key;
            if(character > 'z')
            {
                character = character - 'z' + 'a' - 1;
            }
            str[i] = character;
        }

        //For Capital Letters
        else if(character >= 'A' && character <= 'Z'){
            character = character + key;
            if(character > 'Z')
            {
                character = character - 'Z' + 'A' - 1;
            }
            str[i] = character;
        }
        strncat(result, &str[i], 1);
    }
    printf("Encrypted Message : \n%s\n", result);
}

char *caeser_decrypt(char str[], int key){
    for (int i = 0; i <= strlen(text); i++)
    {
        character = text[i];

        //For Simple Letters
        if (character >= 'a' && character <= 'z')
        {
            character = character + key;
            if(character > 'z')
            {
                character = character + 'z' - 'a' + 1;
            }
            str[i] = character;
        }

        //For Capital Letters
        else if(character >= 'A' && character <= 'Z'){
            character = character + key;
            if(character > 'Z')
            {
                character = character + 'Z' - 'A' + 1;
            }
            str[i] = character;
        }
        strncat(result, &str[i], 1);
    }
    printf("Decrypted Message : \n%s\n", result);
}

/*
Usage:
    -c : Custom_key
    -d : default (the shift by 3)
    -h : help
    Caesar Varients
        -cd_code        : CD code (the shift is 1)
        -jail           : Jail (the shift is 2)    
        -ellen          : Ellen (the shift is 2)
        -cutie          : Cutie (the shift is 3)
        -eiffel         : Eiffel (the shift is 6)
        -wc_code        : WC code (the shift is 6)
        -empty          : Empty (the shift is 7)
        -baden_powell   : Baden Powell (the shift is 14)
        -any            : Any (the shift is 17)
        -see_you        : See You (the shift is 18)
        -i_see          : I_See (the shift is 20)
        -easy           : Easy (the shift is 21)
examples:
    ./caeser -c 4
    ./caeser -d
    ./caeser -ellen
    ./caeser -easy
*/