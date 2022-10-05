#include <stdio.h>

int n = 5;
int c[10] = {12, 1, 2, 1, 4};
int v[10] = {4, 2, 2, 1, 10};
int W = 15;
void simple_fill() {
    int cur_w;
    float tot_v;
    int i, item;
    int used[10];
    for (i = 0; i < n; ++i)
        used[i] = 0;
    cur_w = W;
    while (cur_w > 0) {
        item = -1;
        for (i = 0; i < n; ++i)
            if ((used[i] == 0) &&
                ((item == -1) || ((float)v[i]/c[i] > (float)v[item]/c[item])))
                item = i;
        used[item] = 1;
        cur_w -= c[item];
        tot_v += v[item];
        if (cur_w >= 0)
            printf("Added object %d (%d$, %dKg) completely in the bag. Space left: %d.\n", item + 1, v[item], c[item], cur_w);
        else {
            printf("Added %d%% (%d$, %dKg) of object %d in the bag.\n", (int)((1 + (float)cur_w/c[item]) * 100), v[item], c[item], item + 1);
            tot_v -= v[item];
            tot_v += (1 + (float)cur_w/c[item]) * v[item];
        }
    }
    printf("Filled the bag with objects worth %.2f$.\n", tot_v);
}
int main(int argc, char *argv[]) {
    simple_fill();
    return 0;
}