#include <stdio.h>

#include "hash_set.h"

int main()
{
    hash_set_t *set = init_hash_set();

    int v1 = 10, v2 = 20, v3 = 30, v4 = 40, v5 = 50, v6 = 60, v7 = 70;

    printf("Value %d was add ? %d\n", v1, add(set, &v1));
    printf("Value %d was add ? %d\n", v1, add(set, &v1));
    printf("contains %d ? %d\n", v1, contains(set, &v1));

    printf("Value %d was add ? %d\n", v2, add(set, &v2));
    printf("Value %d was add ? %d\n", v2, add(set, &v2));
    printf("contains %d ? %d\n", v2, contains(set, &v2));

    printf("Value %d was add ? %d\n", v3, add(set, &v3));
    printf("Value %d is add ? %d\n", v3, add(set, &v3));
    printf("contains %d ? %d\n", v3, contains(set, &v3));

    printf("Value %d was add ? %d\n", v4, add(set, &v4));
    printf("Value %d was add ? %d\n", v4, add(set, &v4));
    printf("contains %d ? %d\n", v4, contains(set, &v4));

    printf("Value %d was add ? %d\n", v5, add(set, &v5));
    printf("Value %d was add ? %d\n", v5, add(set, &v5));
    printf("contains %d ? %d\n", v5, contains(set, &v5));

    printf("Value %d is add ? %d\n", v6, add(set, &v6));
    printf("Value %d is add ? %d\n", v6, add(set, &v6));
    printf("contains %d ? %d\n", v6, contains(set, &v6));

    printf("contains %d ? %d\n", v7, contains(set, &v7));

    delete (set, &v6);

    printf("contains %d ? %d\n", v6, contains(set, &v6));

    return 0;
}