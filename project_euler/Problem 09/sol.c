#include <stdio.h>

int main()
{
    int max = 1000, a, b, c, p;

    for (a = 1; a < max; a++){
        for (b = a+1; b < max; b++){
            c = max - a - b;
            if ((a*a + b*b) == c*c){
                printf("%d x %d x %d = %d", a, b, c, a*b*c);
            }

        }
    }
    return 0;
}








