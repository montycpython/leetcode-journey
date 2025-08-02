using System;
using System.Collections.Generic;

public class Solution {
    public long MinCost(int[] basket1, int[] basket2) {
        var freq = new Dictionary<int, int>();
        int minFruit = int.MaxValue;

        // Count net frequency difference
        for (int i = 0; i < basket1.Length; i++) {
            int a = basket1[i], b = basket2[i];
            freq[a] = freq.ContainsKey(a) ? freq[a] + 1 : 1;
            freq[b] = freq.ContainsKey(b) ? freq[b] - 1 : -1;
            minFruit = Math.Min(minFruit, Math.Min(a, b));
        }

        var excess = new List<int>();

        foreach (var kvp in freq) {
            int val = kvp.Key, count = kvp.Value;
            if (count % 2 != 0) return -1;
            int half = Math.Abs(count) / 2;
            for (int i = 0; i < half; i++) excess.Add(val);
        }

        excess.Sort();

        long cost = 0;
        int m = excess.Count;
        for (int i = 0; i < m / 2; i++) {
            cost += Math.Min(excess[i], 2 * minFruit);
        }

        return cost;
    }
}
