#include<stdio.h>
int main()
{
    int stack[50];              //initialize stack
    char str[100];              //initialize the string
    int top = -1;               //give top=-1 so that when first element is scanned index will be 0
    int i = 0;
    printf("Enter string :- ");
    fgets(str,100,stdin);                  //input of string from the user
    while(str[i]!='\0')
    {
        top++;
        stack[top] = str[i];    //store each index char of str in stack    
        i++;
    }
    i = top;                    //give i=top so that we can print the string in reverse
    printf("\nReverse of the string is :- \n");
    while (i != -1)
    {
        printf("%c",stack[i]);  //printf reverse string
        i--;
    }
}
