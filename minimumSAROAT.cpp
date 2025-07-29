class Solution { //minimum-score-after-removals-on-a-tree
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> tree(n);
        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        vector<int> xorSubtree(n), in(n), out(n);
        int time = 0;

        // DFS to compute subtree XORs and Euler Tour timestamps
        function<int(int, int)> dfs = [&](int u, int p) {
            in[u] = time++;
            int x = nums[u];
            for (int v : tree[u]) {
                if (v != p) x ^= dfs(v, u);
            }
            xorSubtree[u] = x;
            out[u] = time++;
            return x;
        };

        int totalXor = dfs(0, -1);
        int minScore = INT_MAX;

        auto isAncestor = [&](int u, int v) {
            return in[u] <= in[v] && out[v] <= out[u];
        };

        // Iterate over all node pairs (excluding root)
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = xorSubtree[i], b = xorSubtree[j], c;

                if (isAncestor(i, j)) {
                    a ^= b;
                    c = totalXor ^ xorSubtree[i];
                } else if (isAncestor(j, i)) {
                    b ^= a;
                    c = totalXor ^ xorSubtree[j];
                } else {
                    c = totalXor ^ a ^ b;
                }

                int maxXor = max({a, b, c});
                int minXor = min({a, b, c});
                minScore = min(minScore, maxXor - minXor);
            }
        }

        return minScore;
    }
};
