from typing import List

class Solution:
    def minimumScore(self, nums: List[int], edges: List[List[int]]) -> int:
        n = len(nums)
        graph = [[] for _ in range(n)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        xor = [0] * n
        tin = [0] * n
        tout = [0] * n
        time = 0

        def dfs(u, parent):
            nonlocal time
            tin[u] = time
            time += 1
            xor[u] = nums[u]
            for v in graph[u]:
                if v != parent:
                    xor[u] ^= dfs(v, u)
            tout[u] = time
            time += 1
            return xor[u]

        dfs(0, -1)
        total = xor[0]

        def is_ancestor(u, v):
            return tin[u] <= tin[v] and tout[v] <= tout[u]

        # Map each edge to its child node
        edge_nodes = []
        for u, v in edges:
            edge_nodes.append(v if is_ancestor(u, v) else u)

        min_score = float('inf')
        for i in range(len(edge_nodes)):
            a = edge_nodes[i]
            for j in range(i + 1, len(edge_nodes)):
                b = edge_nodes[j]
                if is_ancestor(a, b):
                    x1 = xor[b]
                    x2 = xor[a] ^ xor[b]
                    x3 = total ^ xor[a]
                elif is_ancestor(b, a):
                    x1 = xor[a]
                    x2 = xor[b] ^ xor[a]
                    x3 = total ^ xor[b]
                else:
                    x1 = xor[a]
                    x2 = xor[b]
                    x3 = total ^ xor[a] ^ xor[b]
                vals = [x1, x2, x3]
                min_score = min(min_score, max(vals) - min(vals))

        return min_score
