function minimumScore(nums: number[], edges: number[][]): number {
    const n = nums.length;
    const graph: number[][] = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        graph[u].push(v);
        graph[v].push(u);
    }

    const xor: number[] = Array(n).fill(0);
    const tin: number[] = Array(n).fill(0);
    const tout: number[] = Array(n).fill(0);
    let time = 0;

    function dfs(u: number, parent: number): number {
        tin[u] = time++;
        xor[u] = nums[u];
        for (const v of graph[u]) {
            if (v !== parent) {
                xor[u] ^= dfs(v, u);
            }
        }
        tout[u] = time++;
        return xor[u];
    }

    dfs(0, -1);
    const total = xor[0];

    function isAncestor(u: number, v: number): boolean {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }

    const edgeNodes: number[] = [];
    for (const [u, v] of edges) {
        edgeNodes.push(isAncestor(u, v) ? v : u);
    }

    let minScore = Infinity;

    for (let i = 0; i < edgeNodes.length; i++) {
        const a = edgeNodes[i];
        for (let j = i + 1; j < edgeNodes.length; j++) {
            const b = edgeNodes[j];
            let x1: number, x2: number, x3: number;

            if (isAncestor(a, b)) {
                x1 = xor[b];
                x2 = xor[a] ^ xor[b];
                x3 = total ^ xor[a];
            } else if (isAncestor(b, a)) {
                x1 = xor[a];
                x2 = xor[b] ^ xor[a];
                x3 = total ^ xor[b];
            } else {
                x1 = xor[a];
                x2 = xor[b];
                x3 = total ^ xor[a] ^ xor[b];
            }

            const vals = [x1, x2, x3];
            minScore = Math.min(minScore, Math.max(...vals) - Math.min(...vals));
        }
    }

    return minScore;
}
