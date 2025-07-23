import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        // Create a HashMap to store number -> index pairs.
        // In Java, HashMap is equivalent to C++'s unordered_map.
        Map<Integer, Integer> lookup = new HashMap<>(); 

        // Iterate through the array.
        for (int i = 0; i < nums.length; i++) {
            int currentNum = nums[i];
            int complement = target - currentNum;

            // Check if the complement exists in our HashMap.
            // If it does, we've found our two numbers.
            if (lookup.containsKey(complement)) {
                // Return a new int array containing the indices.
                return new int[]{lookup.get(complement), i};
            }

            // If the complement is not found, add the current number and its index to the HashMap.
            lookup.put(currentNum, i);
        }

        // If no solution is found after checking all numbers,
        // return an empty array. The problem statement guarantees a solution exists,
        // so this line should technically not be reached with valid inputs.
        return new int[]{}; 
    }
}
