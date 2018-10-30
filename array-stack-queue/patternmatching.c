#include<stdio.h>
#include<stdlib.h>

 int same(char *,char *,char *,char *);
 
 int main()
{
 
 char STR[100],PAT[100],REP[100],ANS[100];
  int flag;

 printf("enter the main string :\n");
  gets(STR);

 printf("enter the pattern  string :\n");
  gets(PAT);

 printf("enter the replace string :\n");
  gets(REP);

 flag=same(STR,PAT,REP,ANS);

if(flag==1)
 printf("Pattern found and Replaced String is : %s\n ",ANS );
else
 printf("Pattern Not Found\n");

return 0;
}
 

int same(char *STR,char *PAT,char *REP,char *ANS)
{
int i=0,j=0,c=0,k=0,m=0,flag=0;
 
 while(*(STR+m)!='\0')
{
 if(*(STR+m)==*(PAT+i))
  {
     m++,i++;
     if(*(PAT+i)=='\0')
   {
    flag=1;
     for(k=0;*(REP+k)!='\0';k++,j++)
      {*(ANS+j)=*(REP+k);
       i=0;c=m;
      }
   }
  }
else
 {
  *(ANS+j)=*(STR+c);
  j++,c++;m=c;
  i=0;
 }

}
*(ANS+j)='\0';
return flag;
}
