/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    // We'll use a Map to store numbers and their indices.
    // The key will be the number, and the value will be its index in the array.
    const numMap = new Map(); 

    // Loop through the array one number at a time.
    for (let i = 0; i < nums.length; i++) {
        const currentNum = nums[i];
        // Calculate the complement: the number we need to find to hit the target.
        const complement = target - currentNum;

        // Check if our map already contains the complement.
        // If it does, we've found our two numbers!
        if (numMap.has(complement)) {
            // Return an array containing the index of the complement
            // and the index of the current number.
            return [numMap.get(complement), i];
        }

        // If the complement wasn't found, add the current number and its index to the map.
        // This way, it's available for future lookups.
        numMap.set(currentNum, i);
    }

    // According to the problem statement, there will always be exactly one solution,
    // so this line should technically never be reached. However, it's good practice
    // to include a default return in case of unexpected input or problem variations.
    return []; 
};
