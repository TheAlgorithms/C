#include<stdio.h>
int count=0;
void towerOfHanoi(int n, char fromrod, char torod, char auxrod)
{
    if (n == 1)
    {
        printf("\nMove disk 1 from rod %c to rod %c\n", fromrod, torod);
	count++;
        return;
    }
    towerOfHanoi(n-1, fromrod, auxrod, torod);
    printf("\nMove disk %d from rod %c to rod %c\n", n, fromrod, torod);
	count++;
    towerOfHanoi(n-1, auxrod, torod, fromrod);

}
 
int main()
{
    int n; 
    printf("\nEnter the number of disks-:");
    scanf("%d",&n);
    towerOfHanoi(n, 'A', 'C', 'B');
    printf("\nTOTAL NUMBER OF MOVES MADE: %d\n\n",count);  
    return 0;
}
