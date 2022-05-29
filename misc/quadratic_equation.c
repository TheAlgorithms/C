/*
*   Author: Ondrej Kucera (github.com/OndrejKucera77/)
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

int main() {
    float a, b, c, D;

    printf("Programme Quadratic Equation\n");
    printf("---------------------------\n");
    printf("Equation is in the form:\nax^2+bx+c=0\n\n");

    printf("Enter a (shouldn't be 0): ");
    scanf("%f", &a);
    printf("Enter b: ");
    scanf("%f", &b);
    printf("Enter c: ");
    scanf("%f", &c);

    D=(float)pow(b, 2)-4*a*c;

    if (D>0) {
        float x1, x2;

        x1=(-b+(float)pow(D, 0.5))/(2*a);
        x2=(-b-(float)pow(D, 0.5))/(2*a);

        printf("\nEquation has two solutions:\nx1=%.4f\nx2=%.4f", x1, x2);
    }
    else if (D==0) {
        float x;

        x=-b/(2*a);

        printf("\nEquation has one solution:\nx=%.4f", x);
    }
    else {
        printf("\nEquation doesn't have any solutions in R.");
    }

    getch();

    return 0;
}
