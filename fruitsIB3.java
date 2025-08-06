class Solution {
    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        SegmentTree tree = new SegmentTree(baskets);
        int unplaced = 0;

        for (int fruit : fruits) {
            int idx = tree.findAndRemoveLeftmost(0, 0, baskets.length - 1, fruit);
            if (idx == -1) unplaced++;
        }

        return unplaced;
    }

    private static class SegmentTree {
        int[] tree;
        int size;

        SegmentTree(int[] data) {
            size = data.length;
            tree = new int[4 * size];
            build(data, 0, 0, size - 1);
        }

        private void build(int[] data, int node, int l, int r) {
            if (l == r) {
                tree[node] = data[l];
                return;
            }

            int mid = (l + r) / 2;
            build(data, 2 * node + 1, l, mid);
            build(data, 2 * node + 2, mid + 1, r);
            tree[node] = Math.max(tree[2 * node + 1], tree[2 * node + 2]);
        }

        public int findAndRemoveLeftmost(int node, int l, int r, int val) {
            if (tree[node] < val) return -1;

            if (l == r) {
                tree[node] = 0;
                return l;
            }

            int mid = (l + r) / 2;
            int res = findAndRemoveLeftmost(2 * node + 1, l, mid, val);
            if (res == -1)
                res = findAndRemoveLeftmost(2 * node + 2, mid + 1, r, val);

            tree[node] = Math.max(tree[2 * node + 1], tree[2 * node + 2]);
            return res;
        }
    }
}
