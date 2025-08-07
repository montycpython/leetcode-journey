#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<vector<int>>>> dp(2 * n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, INT_MIN))));
        dp[0][0][0][n - 1] = grid[0][0] + grid[0][n - 1] + grid[n - 1][0];

        for (int k = 1; k < 2 * n - 1; ++k) {
            for (int r1 = 0; r1 < n; ++r1) {
                int c1 = k - r1;
                if (c1 < 0 || c1 >= n) continue;
                for (int r2 = 0; r2 < n; ++r2) {
                    int c2 = k - r2;
                    if (c2 < 0 || c2 >= n) continue;
                    for (int r3 = 0; r3 < n; ++r3) {
                        int c3 = k - r3;
                        if (c3 < 0 || c3 >= n) continue;

                        set<pair<int, int>> pos = {{r1, c1}, {r2, c2}, {r3, c3}};
                        int fruit = 0;
                        for (auto& [r, c] : pos) fruit += grid[r][c];

                        for (int dr1 = -1; dr1 <= 0; ++dr1) {
                            int pr1 = r1 + dr1;
                            int pc1 = c1 - (1 + dr1);
                            if (!inBounds(pr1, pc1, n)) continue;
                            for (int dr2 = -1; dr2 <= 0; ++dr2) {
                                int pr2 = r2 + dr2;
                                int pc2 = c2 - (1 + dr2);
                                if (!inBounds(pr2, pc2, n)) continue;
                                for (int dr3 = -1; dr3 <= 0; ++dr3) {
                                    int pr3 = r3 + dr3;
                                    int pc3 = c3 - (1 + dr3);
                                    if (!inBounds(pr3, pc3, n)) continue;

                                    int prev = dp[k - 1][pr1][pr2][pr3];
                                    if (prev != INT_MIN)
                                        dp[k][r1][r2][r3] = max(dp[k][r1][r2][r3], prev + fruit);
                                }
                            }
                        }
                    }
                }
            }
        }

        return dp[2 * n - 2][n - 1][n - 1][n - 1];
    }

private:
    bool inBounds(int r, int c, int n) {
        return r >= 0 && c >= 0 && r < n && c < n;
    }
};
