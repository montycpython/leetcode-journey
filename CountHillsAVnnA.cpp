class Solution {
public:
    int countHillValley(std::vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        // Track the last distinct value to the left
        int left = nums[0];

        for (int i = 1; i + 1 < n; ++i) {
            // Skip if current is equal to next (part of same terrain)
            if (nums[i] == nums[i + 1]) continue;

            // Check for hill or valley
            if ((nums[i] > left && nums[i] > nums[i + 1]) ||
                (nums[i] < left && nums[i] < nums[i + 1])) {
                ++count;
            }

            // Update left only when current is not equal to next
            left = nums[i];
        }

        return count;
    }
};
