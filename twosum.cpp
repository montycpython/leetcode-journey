#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> lookup;  // value -> index
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (lookup.find(complement) != lookup.end()) {
                return {lookup[complement], i};
            }
            lookup[nums[i]] = i;
        }
        return {};  // Return empty if no solution found (though problem says one always exists)
    }
};
