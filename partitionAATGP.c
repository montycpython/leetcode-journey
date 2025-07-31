#include <stdlib.h>

/*Partition array according to given pivot*/

int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
    // Allocate memory for result array
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    // First pass: count how many will go in each partition
    int lessCount = 0, equalCount = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] < pivot) ++lessCount;
        else if (nums[i] == pivot) ++equalCount;
    }

    // Second pass: place elements in result array
    int index = 0;

    // 1. Place less-than-pivot elements (preserve order)
    for (int i = 0; i < numsSize; ++i)
        if (nums[i] < pivot)
            result[index++] = nums[i];

    // 2. Place equal-to-pivot elements
    for (int i = 0; i < numsSize; ++i)
        if (nums[i] == pivot)
            result[index++] = nums[i];

    // 3. Place greater-than-pivot elements (preserve order)
    for (int i = 0; i < numsSize; ++i)
        if (nums[i] > pivot)
            result[index++] = nums[i];

    return result;
}
