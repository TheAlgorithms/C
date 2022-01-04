#include<stdio.h>
int main(){
    int n;
    printf("Enter number of rows:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j==1 || j==i){
                printf("*");
            }else{
                printf(" ");
            }
                
        }
        for(int j=1;j<=2*n-2*i;j++){
            printf(" ");
        }
        for(int j=1;j<=i;j++){
            if(j==1 || j==i){
                printf("*");
            }else{
                printf(" ");
            }
                
        }
        printf("\n");
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            if(j==1 || j==i){
                printf("*");
            }else{
                printf(" ");
            }
                
        }
        for(int j=1;j<=2*n-2*i;j++){
            printf(" ");
        }
        for(int j=1;j<=i;j++){
            if(j==1 || j==i){
                printf("*");
            }else{
                printf(" ");
            }
                
        }
        printf("\n");
    }
    return 0;
}
