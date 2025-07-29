use std::collections::HashSet;

impl Solution {
    pub fn minimum_score(nums: Vec<i32>, edges: Vec<Vec<i32>>) -> i32 {
        let n = nums.len();
        let mut graph = vec![Vec::new(); n];
        for e in edges.iter() {
            let (u, v) = (e[0] as usize, e[1] as usize);
            graph[u].push(v);
            graph[v].push(u);
        }

        let mut xor = vec![0; n];
        let mut in_time = vec![0; n];
        let mut out_time = vec![0; n];
        let mut time = 0;

        fn dfs(u: usize, parent: usize, graph: &Vec<Vec<usize>>, nums: &Vec<i32>,
               xor: &mut Vec<i32>, in_time: &mut Vec<usize>, out_time: &mut Vec<usize>, time: &mut usize) {
            in_time[u] = *time;
            *time += 1;
            xor[u] = nums[u];
            for &v in &graph[u] {
                if v != parent {
                    dfs(v, u, graph, nums, xor, in_time, out_time, time);
                    xor[u] ^= xor[v];
                }
            }
            out_time[u] = *time;
        }

        dfs(0, n, &graph, &nums, &mut xor, &mut in_time, &mut out_time, &mut time);
        let total = xor[0];
        let mut answer = i32::MAX;

        for i in 1..n {
            for j in 1..n {
                if i == j { continue; }

                let (a, b, c) = if in_time[i] < in_time[j] && out_time[j] <= out_time[i] {
                    let x = xor[j];
                    let y = xor[i] ^ xor[j];
                    let z = total ^ xor[i];
                    (x, y, z)
                } else if in_time[j] < in_time[i] && out_time[i] <= out_time[j] {
                    let x = xor[i];
                    let y = xor[j] ^ xor[i];
                    let z = total ^ xor[j];
                    (x, y, z)
                } else {
                    let x = xor[i];
                    let y = xor[j];
                    let z = total ^ x ^ y;
                    (x, y, z)
                };

                let min_val = *[a, b, c].iter().min().unwrap();
                let max_val = *[a, b, c].iter().max().unwrap();
                answer = answer.min(max_val - min_val);
            }
        }

        answer
    }
}
