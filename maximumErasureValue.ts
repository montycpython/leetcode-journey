/* Maximum Erasure Value */

function maximumUniqueSubarray(nums: number[]): number {
    const seen = new Uint8Array(10001); // nums[i] ∈ [1, 10000]
    let left = 0;
    let currentSum = 0;
    let maxSum = 0;

    for (let right = 0; right < nums.length; right++) {
        const num = nums[right];
        while (seen[num]) {
            seen[nums[left]] = 0;
            currentSum -= nums[left];
            left++;
        }
        seen[num] = 1;
        currentSum += num;
        maxSum = Math.max(maxSum, currentSum);
    }

    return maxSum;
}
