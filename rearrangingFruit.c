#include <stdlib.h>
#include <limits.h>

typedef long long ll;

int cmp(const void* a, const void* b) {
    int x = *(int*)a, y = *(int*)b;
    return x - y;
}

// Binary search to find index of val in sorted array arr
int binarySearch(int* arr, int size, int val) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == val) return mid;
        else if (arr[mid] < val) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

ll minCost(int* basket1, int basket1Size, int* basket2, int basket2Size) {
    if (basket1Size != basket2Size) return -1;
    int n = basket1Size;

    int* all = (int*)malloc(sizeof(int) * 2 * n);
    for (int i = 0; i < n; ++i) {
        all[i] = basket1[i];
        all[n + i] = basket2[i];
    }

    // Sort all to extract unique values
    qsort(all, 2 * n, sizeof(int), cmp);

    int* unique = (int*)malloc(sizeof(int) * 2 * n);
    int uniqueCount = 0;
    unique[uniqueCount++] = all[0];
    for (int i = 1; i < 2 * n; ++i) {
        if (all[i] != all[i - 1]) {
            unique[uniqueCount++] = all[i];
        }
    }

    // Frequency arrays
    int* freq1 = (int*)calloc(uniqueCount, sizeof(int));
    int* freq2 = (int*)calloc(uniqueCount, sizeof(int));

    for (int i = 0; i < n; ++i) {
        int idx1 = binarySearch(unique, uniqueCount, basket1[i]);
        int idx2 = binarySearch(unique, uniqueCount, basket2[i]);
        freq1[idx1]++;
        freq2[idx2]++;
    }

    // Check feasibility
    for (int i = 0; i < uniqueCount; ++i) {
        if ((freq1[i] + freq2[i]) % 2 != 0) {
            free(all); free(unique); free(freq1); free(freq2);
            return -1;
        }
    }

    // Collect excess fruits
    int* excess = (int*)malloc(sizeof(int) * n);
    int excessCount = 0;
    int minFruit = unique[0];

    for (int i = 0; i < uniqueCount; ++i) {
        int total = freq1[i] + freq2[i];
        int target = total / 2;
        if (freq1[i] > target) {
            for (int j = 0; j < freq1[i] - target; ++j)
                excess[excessCount++] = unique[i];
        } else if (freq2[i] > target) {
            for (int j = 0; j < freq2[i] - target; ++j)
                excess[excessCount++] = unique[i];
        }
    }

    qsort(excess, excessCount, sizeof(int), cmp);

    ll cost = 0;
    for (int i = 0; i < excessCount / 2; ++i) {
        int x = excess[i];
        int y = excess[excessCount - 1 - i];
        int swapCost = x < y ? x : y;
        int proxyCost = 2 * minFruit;
        cost += (swapCost < proxyCost ? swapCost : proxyCost);
    }

    free(all); free(unique); free(freq1); free(freq2); free(excess);
    return cost;
}
