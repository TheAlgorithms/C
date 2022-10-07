// DDA line drawing algorithm

#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2, dx, dy, steps, k;
    float x, y, xinc, yinc;

    printf("Enter the value of x1 and y1: ");
    scanf("%d%d", &x1, &y1);
    printf("Enter the value of x2 and y2: ");
    scanf("%d%d", &x2, &y2);

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    xinc = dx / (float) steps;
    yinc = dy / (float) steps;

    x = x1;
    y = y1;

    putpixel(x, y, 15);

    for (k = 0; k < steps; k++)
    {
        x += xinc;
        y += yinc;
        putpixel(x, y, 15);
    }

    getch();
    closegraph();
}
