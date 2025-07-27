class Solution {
    public int countHillValley(int[] nums) {
        int count = 0;
        int n = nums.length;

        // Step 1: Create a filtered array without adjacent duplicates
        int[] filtered = new int[n];
        int k = 0;
        filtered[k++] = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                filtered[k++] = nums[i];
            }
        }

        // Step 2: Count hills and valleys
        for (int i = 1; i < k - 1; i++) {
            if (filtered[i] > filtered[i - 1] && filtered[i] > filtered[i + 1]) {
                count++; // Hill
            } else if (filtered[i] < filtered[i - 1] && filtered[i] < filtered[i + 1]) {
                count++; // Valley
            }
        }

        return count;
    }
}
