//program to demonstrate ascending priority
//sucessfulyy working
#include<stdio.h>
int PQ[5]={0};
int insert();
void remove1();
void show();

main(){
    int j,ch=1;
    while(ch!=0){
        printf("\n 1. insert\n 2. remove \n 3. display\n 0. exit");
        printf("enter your choice");
        scanf("%d",&ch);
        switch(ch){
            case 1: insert();
            break;
            case 2: remove1();
            break;
            case 3: show();
            break;
            default: exit(0);
        }
    }
}

int insert(){
    int n,j;
    printf("enter position");
    scanf("%d",&n);
    n--;
    if(n>4||PQ[n]!=0){
        printf("location not available");
        return 0;
    }
    printf("enter element");
    scanf("%d",&j);
    PQ[n]=j;
    return 0;
}

void remove1(){
    int j,k,min=0,s=0;
    for(j=0;j<=4;j++)
    s=s+PQ[j];
    for(j=s;j>0;j--){
        for(k=0;k<5;k++){
            if(j==PQ[k])
            min=PQ[k];
        }
    }
    for(j=0;j<5;j++){
        if(PQ[j]==min){
            PQ[j]=0;
            break;
        }
    }
}

void show(){
    int h;
    for(h=0;h<5;h++)
    printf("%d",PQ[h]);
}
