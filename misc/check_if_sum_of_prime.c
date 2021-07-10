#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>


int checkPrime(int n);

int main()
{
    int n, i, flag = 0;

    system("CLS");
    printf("\n\n\n");
	printf("\n\t ######################################");
	printf("\n\t #                                    #");
	printf("\n\t #           CHECK A NUMBER           #");
	printf("\n\t #           REPRESENTED AS           #");
	printf("\n\t #      SUM OF TWO PRIME NUMBERS      #");
	printf("\n\t #                                    #");
	printf("\n\t ######################################\n");

    Sleep(2000);
    system("CLS");

	printf("\n Enter a positive integer : ");
    scanf("%d", &n);
	printf("\n");


    for(i = 2; i <= n/2 && !kbhit() ; ++i)
    // iterate till i=n/2 and there is no key pressed - interupt
    {
        // condition for i to be a prime number
        if (checkPrime(i) == 1)
        {
            // condition for n-i to be a prime number
            if (checkPrime(n-i) == 1)
            {
                // n = primeNumber1 + primeNumber2
                printf("  %d = %d + %d\n", n, i, n - i);
                flag = 1;
            }

        }
    }

	printf("\a");
    if (flag == 0)
        printf(" %d cannot be expressed as the sum of two prime numbers.\a", n);
        // cannot expressed as sum of two prime numbers


	getch();
	system("CLS");
	return 0;
	// EXIT
}

// Function to check prime number
int checkPrime(int n)
{
    int i, isPrime = 1;

    for(i = 2; i <= n/2; ++i)
    {
        if(n % i == 0)
        {
            isPrime = 0;
            break;
        }
    }

    return isPrime;
}


