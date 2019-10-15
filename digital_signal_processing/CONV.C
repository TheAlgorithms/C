#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#define origX 320
#define origY 240

void axis(int type, int x, int y, int length) {
	int i;
	if (type == 0) {
		line(x - length, y, x + length, y);
		outtextxy(x + length, y + 10, "Time Steps");
	}
	else {
		line(x, y - length, x, y + length);
		outtextxy(x - 10, y - length, "X(n)");
	}
}

void impulse(int x, int val) {
	int new_x = origX + 30*x;
	int new_y = origY - 30*val;
	char x_label[2], y_label[2];
	y_label[0] = (char) (abs(val) + 48);
	y_label[1] = '\0';
	x_label[0] = (char)(abs(x)+48);
	x_label[1] = '\0';
	line(new_x, origY, new_x, new_y);
	outtextxy(new_x, new_y - 10, y_label);
	outtextxy(new_x, origY + 10, x_label);
}

void show_graph(int x[50][2], int l, int colour) {
	int i;
	if (colour == 0)
		setcolor(RED);
	else
		setcolor(YELLOW);
	for (i = 0; i < l; i++)
		impulse(x[i][0], x[i][1]);
	setcolor(WHITE);
}

void reverse(int x[50][2], int l, int result[50][2]) {
	int i;
	for (i = 0; i < l; i++) {
		result[i][0] = -x[l-i-1][0];
		result[i][1] = x[l-i-1][1];
	}
}

int main() {
	int gd = DETECT, gm;
	int i, j, k, len_x, len_h;
	int min_h, max_h;
	int min_x;
	int x[50][2], h[50][2], temp_h[50][2];
	int result[50][2];
	initgraph(&gd, &gm, "");
	axis(0, origX, origY, 240);
	axis(1, origX, origY, 200);
	printf("Enter the length of the signal: ");
	scanf("%d", &len_x);
	printf("Enter the values of the signal in the form (index, value)\n");
	for (i=0; i<len_x; i++)
		scanf("%d %d", &x[i][0], &x[i][1]);
	show_graph(x, len_x, 0);
	printf("Enter the length of the impulse: ");
	scanf("%d", &len_h);
	printf("Enter the values of the signal in the form (index, location)\n");
	for (i=0; i<len_h; i++)
		scanf("%d %d", &temp_h[i][0], &temp_h[i][1]);
	reverse(temp_h, len_h, h);
	//show_graph(h, len_h, 1);
	i = 0;
	for (j = -h[len_h-1][0] + x[0][0]; j <= -h[0][0]+x[len_x-1][0]; j++) {
		result[i][0] = j;
		result[i][1] = 0;
		min_x = x[0][0];
		for (k = 0; k < len_h; k++) {
			if ((h[k][0]+j) >= x[0][0] && (h[k][0]+j) <= x[len_x-1][0])
				result[i][1] += h[k][1] * x[h[k][0]+j-min_x][1];
		}
		i++;
	}

	printf("Result\n");
	for (i = 0; i < (len_x+len_h-1); i++)
		printf("%d --> %d\n", result[i][0], result[i][1]);
	show_graph(result, (len_x + len_h - 1), 1);
	getch();
	closegraph();
	return 0;
}
