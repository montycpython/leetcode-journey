class Solution { //minimum score after removals on a tree
    int[] xorSubtree, in, out;
    int time = 0;

    public int minimumScore(int[] nums, int[][] edges) {
        int n = nums.length;
        List<List<Integer>> tree = new ArrayList<>();
        for (int i = 0; i < n; i++) tree.add(new ArrayList<>());
        for (int[] e : edges) {
            tree.get(e[0]).add(e[1]);
            tree.get(e[1]).add(e[0]);
        }

        xorSubtree = new int[n];
        in = new int[n];
        out = new int[n];
        dfs(0, -1, nums, tree);

        int totalXor = xorSubtree[0];
        int minScore = Integer.MAX_VALUE;

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
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

                int max = Math.max(a, Math.max(b, c));
                int min = Math.min(a, Math.min(b, c));
                minScore = Math.min(minScore, max - min);
            }
        }

        return minScore;
    }

    private void dfs(int node, int parent, int[] nums, List<List<Integer>> tree) {
        in[node] = time++;
        int xor = nums[node];
        for (int child : tree.get(node)) {
            if (child != parent) {
                dfs(child, node, nums, tree);
                xor ^= xorSubtree[child];
            }
        }
        xorSubtree[node] = xor;
        out[node] = time++;
    }

    private boolean isAncestor(int u, int v) {
        return in[u] <= in[v] && out[v] <= out[u];
    }
}
