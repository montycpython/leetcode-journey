/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* smallestSubarrays(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    int lastSeen[32];  // Tracks last index where each bit is seen

    for (int i = 0; i < 32; i++) {
        lastSeen[i] = -1;
    }

    for (int i = numsSize - 1; i >= 0; i--) {
        for (int bit = 0; bit < 32; bit++) {
            if ((nums[i] >> bit) & 1) {
                lastSeen[bit] = i;
            }
        }

        int maxIndex = i;
        for (int bit = 0; bit < 32; bit++) {
            if (lastSeen[bit] > maxIndex) {
                maxIndex = lastSeen[bit];
            }
        }

        result[i] = maxIndex - i + 1;
    }

    *returnSize = numsSize;
    return result;
}
