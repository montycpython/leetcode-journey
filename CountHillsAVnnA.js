function countHillValley(nums) {
    // Step 1: Filter adjacent duplicates
    const filtered = [nums[0]];
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] !== nums[i - 1]) {
            filtered.push(nums[i]);
        }
    }

    // Step 2: Count hills and valleys
    let count = 0;
    for (let i = 1; i < filtered.length - 1; i++) {
        if (
            (filtered[i] > filtered[i - 1] && filtered[i] > filtered[i + 1]) ||
            (filtered[i] < filtered[i - 1] && filtered[i] < filtered[i + 1])
        ) {
            count++;
        }
    }

    return count;
}
