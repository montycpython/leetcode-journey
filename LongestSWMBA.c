int longestSubarray(int* nums, int numsSize) {
    int max_val = nums[0];
    int curr_len = 0, longest = 0;

    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] > max_val) {
            max_val = nums[i];
            curr_len = 1;
            longest = 1;
        } else if (nums[i] == max_val) {
            curr_len++;
            if (curr_len > longest)
                longest = curr_len;
        } else {
            curr_len = 0;
        }
    }
    return longest;
}
