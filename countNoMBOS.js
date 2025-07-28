/**
 * @param {number[]} nums
 * @return {number}
 */
var countMaxOrSubsets = function(nums) {
    const n = nums.length;
    let maxOr = 0, count = 0;

    // Step 1: Compute the maximum OR value
    for (let num of nums) {
        maxOr |= num;
    }

    const total = 1 << n;

    // Step 2: Enumerate subsets using bitmasking
    for (let mask = 1; mask < total; mask++) {
        let currentOr = 0;
        let i = 0, temp = mask;

        // Fast bit iteration using shift (no extra memory)
        while (temp !== 0) {
            if (temp & 1) currentOr |= nums[i];
            temp >>= 1;
            i++;
        }

        if (currentOr === maxOr) count++;
    }

    return count;
};
