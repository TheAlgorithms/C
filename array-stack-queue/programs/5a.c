#include<stdio.h>

void tower(int,char,char,char);

 char source,det,aux;
 int n;

 void main(){
  printf("Enter The NO. oF Disk's : \n");
   scanf("%d",&n);

  tower(n,'A','B','C');
}

 void tower(int n,char source,char aux,char dest){
   if(n==1)
     printf("Move Disk From %c to %c \n",source,dest);
      
   else 
 {
  tower(n-1,source,dest,aux);
   printf("Move Remaining Disks From %c to %c\n",source,dest);
  tower(n-1,aux,source,dest);
 }
}
