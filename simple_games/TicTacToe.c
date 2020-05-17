#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void singlemode();
void doublemode();
void placex(int);
void place();
void placey(int);
int checkwin();
char a[9];
void main()
{
int l = 0;
do
{
int n=0;
for(int i = 0;i<9;i++)
a[i] = '*';
printf("***************************************\n");
printf("*************TIC TAC TOE***************\n");
printf("***************************************\n");
printf("***********1. YOU vs COMPUTER ***********\n");
printf("***********2. YOU vs PLAYER ***********\n");
printf("***********3.EXIT *********************\n");
printf("Enter your choice : ");
scanf("%d",&n);
switch(n)
{
case 1:singlemode();
break;
case 2:doublemode();
break;
default: printf("THANK YOU and EXIT!");
}
printf("Next game ? : ");
printf("Enter 1 – YES and 0 - NO ");
scanf("%d",&l);
}while(l==1);
}
void singlemode()
{
int m;
int k=0;
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
printf("%c ",a[k]);
k++;
}
printf("\n");
}

for(int x=1;x<10;x++)
{
k=0;
printf("Where would you like to place 'x' ");
scanf("%d",&m);
placex(m);
place();
for(int i=0;i<3;i++)
{

for(int j=0;j<3;j++)
{
printf("%c ",a[k]);
k++;
}
printf("\n");
}
int o=checkwin();
if(o==-1 || o==-2)
{
if(o==-1)
printf("YOU WIN\n");
if(o==-2)
printf("YOU LOSE\n");
break;
}
if(o==0 && x==9)
{
printf("\nDRAW");
break;
}
}
}
void doublemode()
{
int m;int e1;
int k=0;
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
printf("%c ",a[k]);
k++;
}
printf("\n");
}
for(int x=1;x<10;x++)
{
k=0;
printf("PLAYER1 - where would you like to place 'x' : ");
scanf("%d",&m);
placex(m);
printf("PLAYER2 - where would you like to place 'o' : ");
scanf("%d",&e1);
placey(e1);
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
printf("%c ",a[k]);
k++;
}
printf("\n");
}
int o=checkwin();
if(o==-1 || o==-2)
{
if(o==-1)
printf("Player 1 WIN\n");
if(o==-2)
printf("Player 2 WIN\n");

break;
}
if(o==0 && x==9)
{
printf("\nDRAW");
break;
}
}
}

void placex(int m)
{
int n1;
if(m>=1 && m<=9)
{
if(a[m-1]!='x' && a[m-1]!='o')
a[m-1]='x';
else
{
printf("Invalid move\n");
printf("Enter new position : ");
scanf("%d",&n1);
placex(n1);
}
}
else
{
printf("Invalid move \n");
printf("Enter new position : ");
scanf("%d",&n1);
placex(n1);
}
}

void place()
{
srand(time(NULL));
int e=rand()%9;
if(e>=0 && e<=8)
{
if(a[e]!='x' && a[e]!='o')
{

a[e]='o';
printf("\n jarvis placed at %d position\n",e+1);
}
else
place();
}
}

void placey(int e1)
{
int n1;
if(e1>=1&& e1<=9)
{
if(a[e1-1]!='x' && a[e1-1]!='o')
a[e1-1]='o';
else
{
printf("Invalid move \n");
printf("Enter new position : ");
scanf("%d",&n1);
placey(n1);
}
}
else
{
printf("Invalid move \n");
printf("Enter new position : ");
scanf("%d",&n1);
placey(n1);
}
}

int checkwin()
{
if (a[0] == a[1] && a[1] == a[2])
{
if(a[0]=='x' && a[1]=='x' && a[2]=='x')
return -1;
if(a[0]=='o' && a[1]=='o' && a[2]=='o')
return -2;
}
else if (a[0] == a[4] && a[4] == a[8])

{
if(a[0]=='x' && a[4]=='x' && a[8]=='x')
return -1;
if(a[0]=='o' && a[4]=='o' && a[8]=='o')
return -2;
}
else if (a[0] == a[3] && a[3] == a[6])
{
if(a[0]=='x' && a[3]=='x' && a[6]=='x')
return -1;
if(a[0]=='o' && a[3]=='o' && a[6]=='o')
return -2;
}
else if (a[3] == a[4] && a[4] == a[5])
{
if(a[3]=='x' && a[4]=='x' && a[5]=='x')
return -1;
if(a[3]=='o' && a[4]=='o' && a[5]=='o')
return -2;
}
else if (a[6] == a[7] && a[7] == a[8])
{
if(a[6]=='x' && a[7]=='x' && a[8]=='x')
return -1;
if(a[6]=='o' && a[7]=='o' && a[8]=='o')
return -2;
}
else if (a[1] == a[4] && a[4] == a[7])
{
if(a[1]=='x' && a[4]=='x' && a[7]=='x')
return -1;

if(a[1]=='o' && a[4]=='o' && a[7]=='o')
return -2;
}
else if (a[2]== a[5] && a[5] == a[8])
{
if(a[2]=='x' && a[5]=='x' && a[8]=='x')
return -1;
if(a[2]=='o' && a[5]=='o' && a[8]=='o')
return -2;
}
else if (a[2] == a[4] && a[4] == a[6])
{
if(a[2]=='x' && a[4]=='x' && a[6]=='x')
return -1;
if(a[2]=='o' && a[4]=='o' && a[6]=='o')
return -2;
}
else
return 0;
}


