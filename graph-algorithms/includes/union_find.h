#ifndef UNIONFIND_H
#define UNIONFIND_H

typedef int* UnionFind;

UnionFind createUnionFind(int size);
int getRoot(UnionFind uf, int el);
int isSameSet(UnionFind uf, int el1, int el2);
void mergeSets(UnionFind uf, int el1, int el2);
    
#endif //UNIONFIND_H