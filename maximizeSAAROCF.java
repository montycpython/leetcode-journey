import java.util.*;

class Solution {
    public long maxSubarrays(int n, int[][] conflictingPairs) {
        // conflicts[r] stores the left endpoints that conflict with subarrays ending at r
        List<List<Integer>> conflicts = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            conflicts.add(new ArrayList<>());
        }

        for (int[] pair : conflictingPairs) {
            int a = pair[0];
            int b = pair[1];
            conflicts.get(Math.max(a, b)).add(Math.min(a, b));
        }

        long totalValidSubarrays = 0;
        long[] gains = new long[n + 1];
        int maxLeft = 0;
        int secondMaxLeft = 0;

        for (int right = 1; right <= n; right++) {
            for (int left : conflicts.get(right)) {
                if (left > maxLeft) {
                    secondMaxLeft = maxLeft;
                    maxLeft = left;
                } else if (left > secondMaxLeft) {
                    secondMaxLeft = left;
                }
            }

            // Subarrays from [maxLeft + 1, right] to [right, right] are valid
            totalValidSubarrays += right - maxLeft;

            // If we remove maxLeft, we gain subarrays from [secondMaxLeft + 1, right] to [maxLeft, right]
            if (maxLeft > 0) {
                gains[maxLeft] += maxLeft - secondMaxLeft;
            }
        }

        long maxGain = 0;
        for (long gain : gains) {
            maxGain = Math.max(maxGain, gain);
        }

        return totalValidSubarrays + maxGain;
    }
}
