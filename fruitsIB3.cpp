class Solution {
public:
    int numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets) {
        SegmentTree tree(baskets);
        int unplaced = 0;

        for (int fruit : fruits) {
            int idx = tree.findAndRemoveLeftmost(0, 0, baskets.size() - 1, fruit);
            if (idx == -1) ++unplaced;
        }

        return unplaced;
    }

private:
    class SegmentTree {
    public:
        SegmentTree(const std::vector<int>& data) {
            n = data.size();
            tree.resize(4 * n);
            build(data, 0, 0, n - 1);
        }

        int findAndRemoveLeftmost(int node, int l, int r, int val) {
            if (tree[node] < val) return -1;
            if (l == r) {
                tree[node] = 0;
                return l;
            }

            int mid = (l + r) / 2;
            int res = findAndRemoveLeftmost(2 * node + 1, l, mid, val);
            if (res == -1)
                res = findAndRemoveLeftmost(2 * node + 2, mid + 1, r, val);

            tree[node] = std::max(tree[2 * node + 1], tree[2 * node + 2]);
            return res;
        }

    private:
        int n;
        std::vector<int> tree;

        void build(const std::vector<int>& data, int node, int l, int r) {
            if (l == r) {
                tree[node] = data[l];
                return;
            }

            int mid = (l + r) / 2;
            build(data, 2 * node + 1, l, mid);
            build(data, 2 * node + 2, mid + 1, r);
            tree[node] = std::max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    };
};
