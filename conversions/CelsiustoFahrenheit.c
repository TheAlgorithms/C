#include<stdio.h>

int main()
{
    printf("\n\n\t\tStudytonight - Best place to learn\n\n\n");
    
    float celsius, fahrenheit;
    printf("\n\nEnter temperature in Celsius: ");
    scanf("%f", &celsius);
    
    fahrenheit = (1.8*celsius) + 32;
    
    printf("\n\n\nTemperature in Fahrenheit is: %f ", fahrenheit);
    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return 0;
}
