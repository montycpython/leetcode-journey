using System;

public class Solution {
    public long PutMarbles(int[] weights, int k) {
        int n = weights.Length;
        int splits = k - 1;

        // We only need to store (n - 1) pair sums temporarily
        Span<long> pairSums = stackalloc long[n - 1];

        for (int i = 0; i < n - 1; i++) {
            pairSums[i] = (long)weights[i] + weights[i + 1];
        }

        // Sort the pair sums in-place
        pairSums.Sort();

        long minScore = 0, maxScore = 0;

        // Sum smallest (k-1) for min score
        for (int i = 0; i < splits; i++) {
            minScore += pairSums[i];
        }

        // Sum largest (k-1) for max score
        for (int i = n - 2; i >= n - 1 - splits; i--) {
            maxScore += pairSums[i];
        }

        return maxScore - minScore;
    }
}
