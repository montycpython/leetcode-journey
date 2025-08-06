#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

void build(int* tree, int* baskets, int node, int l, int r) {
    if (l == r) {
        tree[node] = baskets[l];
        return;
    }
    int mid = (l + r) / 2;
    build(tree, baskets, 2 * node + 1, l, mid);
    build(tree, baskets, 2 * node + 2, mid + 1, r);
    tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
}

int queryAndUpdate(int* tree, int node, int l, int r, int val) {
    if (tree[node] < val) return -1;

    if (l == r) {
        tree[node] = 0;
        return l;
    }

    int mid = (l + r) / 2;
    int res = queryAndUpdate(tree, 2 * node + 1, l, mid, val);
    if (res == -1)
        res = queryAndUpdate(tree, 2 * node + 2, mid + 1, r, val);

    tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    return res;
}

int numOfUnplacedFruits(int* fruits, int fruitsSize, int* baskets, int basketsSize) {
    int treeSize = 4 * basketsSize;
    int* tree = (int*)malloc(sizeof(int) * treeSize);
    build(tree, baskets, 0, 0, basketsSize - 1);

    int unplaced = 0;
    for (int i = 0; i < fruitsSize; ++i) {
        int idx = queryAndUpdate(tree, 0, 0, basketsSize - 1, fruits[i]);
        if (idx == -1) ++unplaced;
    }

    free(tree);
    return unplaced;
}
