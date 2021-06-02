#include <stdio.h>
#include <stdlib.h>

#include "../includes/union_find.h"

UnionFind createUnionFind(int size) {
    UnionFind uf = malloc(size * sizeof(int));

    int i;

    for (i = 0; i < size; ++i) uf[i] = -1;

    return uf;
}

int getRoot(UnionFind uf, int el) {
    
    if (uf[el] < 0) return el;
    return getRoot(uf, uf[el]);
}

int isSameSet(UnionFind uf, int el1, int el2) {
    return getRoot(uf, el1) == getRoot(uf, el2);
}

void mergeSets(UnionFind uf, int el1, int el2) {

    el1 = getRoot(uf, el1);
    el2 = getRoot(uf, el2);

    if (el1 == el2) return;

    if (uf[el1] < uf[el2]) {

        int aux = uf[el1];
        uf[el1] = uf[el2];
        uf[el2] = aux;
    }

    uf[el2] += uf[el1];
    uf[el1] = el2;
}