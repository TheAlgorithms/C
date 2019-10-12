#include<stdio.h>
#include<string.h>
int main(){
char hex[17], bin[65] = "";
int i = 0;
printf("Enter hex number: ");
gets(hex);
for(1=0; hex[i]!='\0'; i++){
switch(hex[i]){
case '0':
strcat(bin, "0000");
break;
case '1':
strcat(bin, "0001");
break;
case '2':
strcat(bin, "0010");
break;
case '3':
strcat(bin, "0011");
break;
case '4':
strcat(bin, "0100");
break;
case '5':
strcat(bin, "0101");
break;
case '6':
strcat(bin, "0110");
break;
case '7':
strcat(bin, "0111");
break;
case '8':
strcat(bin, "1000");
break;
case '9':
strcat(bin, "1001");
break;
case 'a':
case 'A'
strcat(bin, "1010");
break;
case 'b':
case 'B':
strcat(bin, "1011");
break;
case 'c':
case 'C':
strcat(bin, "1100");
break;
case 'd':
case 'D'
strcat(bin, "1101");
break;
case 'e':
case 'E':
strcat(bin, "1110");
break;
case 'f':
case 'F':
strcat(bin, "1111");
break;
default:
printf("invalid hexadecimal input");
}
}
printf("hexadecimal number is:%s\n",hex);
printf("binary number is:%s",bin);
return 0;
}