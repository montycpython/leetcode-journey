/**
 * @param {number} n
 * @param {number[][]} conflictingPairs
 * @return {number}
 */
var maxSubarrays = function(n, conflictingPairs) {
    // conflicts[r] stores left endpoints that conflict with subarrays ending at r
    const conflicts = Array.from({ length: n + 1 }, () => []);

    for (const [a, b] of conflictingPairs) {
        const maxVal = Math.max(a, b);
        const minVal = Math.min(a, b);
        conflicts[maxVal].push(minVal);
    }

    let totalValidSubarrays = 0;
    const gains = Array(n + 1).fill(0);
    let maxLeft = 0;
    let secondMaxLeft = 0;

    for (let right = 1; right <= n; right++) {
        for (const left of conflicts[right]) {
            if (left > maxLeft) {
                secondMaxLeft = maxLeft;
                maxLeft = left;
            } else if (left > secondMaxLeft) {
                secondMaxLeft = left;
            }
        }

        totalValidSubarrays += right - maxLeft;

        if (maxLeft > 0) {
            gains[maxLeft] += maxLeft - secondMaxLeft;
        }
    }

    const maxGain = Math.max(...gains);
    return totalValidSubarrays + maxGain;
};
