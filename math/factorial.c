/*
 Program to compute factorial of large numbers using array storage.
 Handles values beyond standard integer limits.
*/
#include <stdio.h> //for basic functions like printf,scanf etc
int main()
{
    int a[200], n, counter, temp, i;      //initialize variables and arrays
    a[0] = 1;    //first element of the array to be 1
    counter = 0;    //to track number of digits in result
    printf("Enter a whole number to Find its Factorial: ");
    scanf("%d", &n);    //take input number and store to variable n
    if (n < 0)    //factorial not defined for negatives
        printf("Cannot Calculate factorials for negative numbers.");
    else
    {
        for (; n >= 2; n--)
        {
            temp = 0;    //for carry during multiplication
            for (i = 0; i <= counter; i++)
            {
                temp = (a[i] * n) + temp;    //multiply digit and add previous carry
                a[i] = temp % 10;    //store last digit of result
                temp = temp / 10;    //update carry 
            }
            //store remaining carry digits in array
            while (temp > 0)
            {
                a[++counter] = temp % 10;
                temp = temp / 10;
            }
        }
        //print factorial in msd order 
        for (i = counter; i >= 0; i--) printf("%d", a[i]);
    }
    return 0;
}
