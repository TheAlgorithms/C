#include <math.h>
#include <stdio.h>
/**
 * Author Arnab Nath
 * The code is implemented in VS Code
 */
/*
 * imported the math.h header to implement various mathematical functions.
 * imported the stlib.h header whidh is the general standard  purpose library of
 * C programming language.
 */

// Function to calculate distance between 2 points
// The X and Y coordinates are the parameters of the function
float distance(int x1, int y1, int x2, int y2)
{
    // Calculating distance
    /* Formula to calculate the distance between 2 points is
    d=√((x2 – x1)² + (y2 – y1)²). */
    // Return the value
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}

int main()
{
    /*initialising the input variables i.e., the coordinates of the 2 points*/
    int x1, x2, y1, y2;
    /*Take input for the X and Y coordinate of first point*/
    printf("Enter the X and Y Coordinates of First Point: ");
    scanf("%d %d", &x1, &y1);
    /*Take input for the X and Y coordinate of second point*/
    printf("Enter the X and Y Coordinates of Second Point: ");
    scanf("%d %d", &x2, &y2);
    /*Printing the distance between 2 points by calling the distance function*/
    printf("%f", distance(x1, y1, x2, y2));
    return 0;
}
