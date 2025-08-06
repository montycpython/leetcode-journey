public class Solution {
    public int NumOfUnplacedFruits(int[] fruits, int[] baskets) {
        int n = baskets.Length;
        SegmentTree segTree = new SegmentTree(baskets);
        int unplacedCount = 0;

        foreach (int fruit in fruits) {
            int position = segTree.FindAndRemoveLeftmost(fruit);
            if (position == -1) {
                unplacedCount++;
            }
        }

        return unplacedCount;
    }

    // Segment Tree class for range max queries and updates
    private class SegmentTree {
        private int[] tree;
        private int[] arr;
        private int n;

        public SegmentTree(int[] input) {
            n = input.Length;
            arr = new int[n];
            input.CopyTo(arr, 0);
            tree = new int[4 * n];
            Build(0, 0, n - 1);
        }

        private void Build(int node, int start, int end) {
            if (start == end) {
                tree[node] = arr[start];
            } else {
                int mid = (start + end) / 2;
                Build(2 * node + 1, start, mid);
                Build(2 * node + 2, mid + 1, end);
                tree[node] = Math.Max(tree[2 * node + 1], tree[2 * node + 2]);
            }
        }

        public int FindAndRemoveLeftmost(int value) {
            return QueryAndUpdate(0, 0, n - 1, value);
        }

        private int QueryAndUpdate(int node, int start, int end, int value) {
            if (tree[node] < value) return -1;

            if (start == end) {
                tree[node] = 0;
                arr[start] = 0;
                return start;
            }

            int mid = (start + end) / 2;
            int leftResult = QueryAndUpdate(2 * node + 1, start, mid, value);
            if (leftResult != -1) {
                tree[node] = Math.Max(tree[2 * node + 1], tree[2 * node + 2]);
                return leftResult;
            }

            int rightResult = QueryAndUpdate(2 * node + 2, mid + 1, end, value);
            if (rightResult != -1) {
                tree[node] = Math.Max(tree[2 * node + 1], tree[2 * node + 2]);
                return rightResult;
            }

            return -1;
        }
    }
}
