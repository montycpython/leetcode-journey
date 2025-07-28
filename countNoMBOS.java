class Solution {
    public int countMaxOrSubsets(int[] nums) {
        int n = nums.length;
        int maxOr = 0, count = 0;

        // Compute the maximum OR value
        for (int num : nums) {
            maxOr |= num;
        }

        int total = 1 << n;

        // Enumerate all subsets using bitmask
        for (int mask = 1; mask < total; mask++) {
            int currentOr = 0;
            int temp = mask;

            // Fast bit iteration using Brian Kernighan’s trick
            for (int i = 0; temp != 0; i++) {
                if ((temp & 1) != 0) {
                    currentOr |= nums[i];
                }
                temp >>= 1;
            }

            if (currentOr == maxOr) {
                count++;
            }
        }

        return count;
    }
}
