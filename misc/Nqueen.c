/** "N-queen" problem is based on backtracking.
 * Here this code shows total number of solutions
 * with complete solution for a given size of board.
 * Here key function is "queen" and for display 
 * solution there are "print_sol" function.
 * To check weather the putting position of queen is
 * safe or not is chacked by "place" function.
 */


#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int a[30],count=0;
int place(int pos)
{
    int i;
    for(i=1;i<pos;i++)
    {
        if((a[i]==a[pos]) || ((abs(a[i]-a[pos])==abs(i-pos))))
        {
            return 0;
        }
    }
    return 1;
}
void print_sol(int n)
{
    int i,j;
    count++;
    printf("solution number : %d\n",count);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i]==j)
            {
                printf("* ");
            }
            else
            {
                printf("- ");
            }
        }
        printf("\n");
    }
}
void queen(int n)
{
    int k=1;
    a[k]=0;
    while (k!=0)
    {
        a[k] = a[k]+1;
        while ((a[k]<=n) && !place(k))
        {
            a[k]++;
        }
        if(a[k]<=n)
        {
            if(k==n)
            {
                print_sol(n);
            }
            else
            {
                k++;
                a[k]=0;
            }
        }
        else
        {
            k--;
        }
    }
}

//Main function : 

int main()
{
    int i,n;
    printf("Enter the size of board : ");
    scanf("%d",&n);
    queen(n);
    printf("solution : ");
    return 0;
}