#include <vector>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        vector<int> count(n, 0);
        int left = 0, max_len = 0, unique = 0;

        for (int right = 0; right < n; ++right) {
            if (count[fruits[right]]++ == 0)
                ++unique;
            while (unique > 2) {
                if (--count[fruits[left]] == 0)
                    --unique;
                ++left;
            }
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};
