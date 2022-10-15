#include <math.h>
#include <stdio.h>

// Function to calculate distance
float distance(int x1, int y1, int x2, int y2)
{
    // Calculating distance
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}

// Drivers Code
int main()
{
    int x1, x2, y1, y2;
    printf("Enter the X and Y Coordinates of First Point: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the X and Y Coordinates of Second Point: ");
    scanf("%d %d", &x2, &y2);
    printf("%f", distance(x1, y1, x2, y2));
    return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
