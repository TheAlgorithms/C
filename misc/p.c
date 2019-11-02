#include<stdio.h>
#include<conio.h>
void main()
{
	char s1[20];
	int i,l,flag=0;
	clrscr();
	printf("Enter string:\t");
	gets(s1);
	l=strlen(s1);
	l=l-1;
	for(i=0;i<l/2;i++)
	{
		if(s1[i]!=s1[l-i])
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("\n%s is a palindrome.",s1);
	else
		printf("\n%s is not a palindrome !",s1);
	getch();
}
