#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> triangle;
        std::vector<int> prev, curr;

        for (int i = 0; i < numRows; ++i) {
            curr.clear();
            curr.push_back(1); // First element is always 1

            for (int j = 1; j < i; ++j) {
                curr.push_back(prev[j - 1] + prev[j]);
            }

            if (i > 0) {
                curr.push_back(1); // Last element is always 1
            }

            triangle.push_back(curr);
            std::swap(prev, curr);
        }

        return triangle;
    }
};
