// Binary number to octal number conversion
#include<stdio.h>

//Function that returns the last three digits
int three_digits(int n)
{
    int r, d = 0, p=1;

    for(int i=0; i<3; i++)
    {
        r = n%10;
        d += r * p;
        p *= 10;
        n /= 10;
    }
    return d;
}

int main(void)
{
    int binary_num, d=0, base=1, remainder, td, res=0, ord=1;

    printf("Enter the binary no: ");
    scanf("%d", &binary_num);

    while(binary_num > 0)
    {
        if(binary_num > 111) //Checking if binary number is greater than three digits
            td = three_digits(binary_num);

        else td = binary_num;

        binary_num /= 1000;

        d = 0, base =1;

        // Converting the last three digits to decimal
        while(td > 0)
        {
            remainder = td % 10;
            td /= 10;
            d += (base * remainder);
            base *= 2;
        }

        res += d * ord; // Calculating the octal value
        ord *= 10;
    }

    printf("\nOctal equivalent is: %d", res);
    return 0;
}
