class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> lastSeen(32, -1);   // Track last index each bit appears
        vector<int> result(n);

        for (int i = n - 1; i >= 0; --i) {
            // Update last seen index for each bit present in nums[i]
            for (int bit = 0; bit < 32; ++bit) {
                if ((nums[i] >> bit) & 1) {
                    lastSeen[bit] = i;
                }
            }

            // Determine how far we must extend the subarray to capture all active bits
            int maxIdx = i;
            for (int bit = 0; bit < 32; ++bit) {
                if (lastSeen[bit] != -1) {
                    maxIdx = max(maxIdx, lastSeen[bit]);
                }
            }

            result[i] = maxIdx - i + 1;
        }

        return result;
    }
};
