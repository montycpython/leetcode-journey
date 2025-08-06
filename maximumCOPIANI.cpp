#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // Find the first index of 0 or greater
        int firstNonNegative = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        // Find the first index of strictly positive
        int firstPositive = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();

        int negCount = firstNonNegative;
        int posCount = nums.size() - firstPositive;

        return max(negCount, posCount);
    }
};
