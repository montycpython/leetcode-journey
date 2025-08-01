class Solution { //maximizeSubArraysAfterRemovingOneConflictingPair
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>> conflicts(n + 1);
        for (const auto& pair : conflictingPairs) {
            int a = pair[0], b = pair[1];
            conflicts[max(a, b)].push_back(min(a, b));
        }

        long long validSubarrays = 0;
        vector<long long> gains(n + 1, 0);
        int maxLeft = 0, secondMaxLeft = 0;

        for (int right = 1; right <= n; ++right) {
            for (int left : conflicts[right]) {
                if (left > maxLeft) {
                    secondMaxLeft = maxLeft;
                    maxLeft = left;
                } else if (left > secondMaxLeft) {
                    secondMaxLeft = left;
                }
            }

            validSubarrays += right - maxLeft;
            gains[maxLeft] += maxLeft - secondMaxLeft;
        }

        return validSubarrays + *max_element(gains.begin(), gains.end());
    }
};
