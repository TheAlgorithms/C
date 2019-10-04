#include <stdio.h>
int main()
{
    int array[11] = {2,3,4,5,6,7,8,9,22,33,45};
    int low       = 0;
    int high      = 10;
    int flag      = 0;
    int s         = 4;

    while(low <= high){
        int index = low+(high-low)/2;
        if(array[index] == s){
            flag = 1;
            printf("Founded: %d \n",index);
            break;
        }
        else if(array[index] < s){
            low   = index+1;
        }
        else{
            high = index-1;
        }
    }
    if(flag == 0){
        printf("Not Found!\n");
    }

    return 0;
}
