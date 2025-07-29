function smallestSubarrays(nums: number[]): number[] {
    const n = nums.length;
    const lastSeen: number[] = new Array(32).fill(-1); // Track last seen index for each bit
    const result: number[] = new Array(n).fill(0);

    for (let i = n - 1; i >= 0; i--) {
        // Update the last seen index for each bit in nums[i]
        for (let bit = 0; bit < 32; bit++) {
            if ((nums[i] >> bit) & 1) {
                lastSeen[bit] = i;
            }
        }

        // Determine the furthest index needed to reach the max OR
        let maxIdx = i;
        for (let bit = 0; bit < 32; bit++) {
            if (lastSeen[bit] !== -1) {
                maxIdx = Math.max(maxIdx, lastSeen[bit]);
            }
        }

        result[i] = maxIdx - i + 1;
    }

    return result;
}
