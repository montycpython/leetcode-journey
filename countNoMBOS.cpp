class Solution {
public:
    int countMaxOrSubsets(std::vector<int>& nums) {
        int n = nums.size();
        int maxOr = 0, count = 0;

        // Compute the maximum OR value
        for (int num : nums) {
            maxOr |= num;
        }

        // Enumerate all subsets using bitmask
        for (int mask = 1; mask < (1 << n); ++mask) {
            int currentOr = 0;

            // Inline OR computation without extra memory
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    currentOr |= nums[i];
                }
            }

            if (currentOr == maxOr) {
                ++count;
            }
        }

        return count;
    }
};
