int lowerBound(int* nums, int numsSize, int target) { //maximum-count-of-positive-integer-and-negative-intege
    int left = 0, right = numsSize;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int maximumCount(int* nums, int numsSize) {
    int firstNonNegative = lowerBound(nums, numsSize, 0);  // index of first 0 or positive
    int firstPositive = lowerBound(nums, numsSize, 1);     // index of first strictly positive

    int negCount = firstNonNegative;
    int posCount = numsSize - firstPositive;

    return negCount > posCount ? negCount : posCount;
}
