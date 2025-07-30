#include <vector>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int maxVal = 0, maxLen = 0, currLen = 0;

        for (int num : nums) {
            if (num > maxVal) {
                maxVal = num;
                maxLen = currLen = 1;
            } else if (num == maxVal) {
                ++currLen;
                if (currLen > maxLen) maxLen = currLen;
            } else {
                currLen = 0;
            }
        }
        return maxLen;
    }
};
