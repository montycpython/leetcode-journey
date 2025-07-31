#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> curr;

        for (int num : arr) {
            unordered_set<int> next;
            next.insert(num);
            for (int val : curr)
                next.insert(val | num);
            curr = std::move(next);
            result.insert(curr.begin(), curr.end());
        }

        return result.size();
    }
};
