public class Solution {
    public int[] SmallestSubarrays(int[] nums) {
        int n = nums.Length;
        int[] res = new int[n];
        int[] last = new int[32]; // track last index where each bit appears

        for (int i = n - 1; i >= 0; i--) {
            for (int bit = 0; bit < 32; bit++) {
                if ((nums[i] & (1 << bit)) > 0) {
                    last[bit] = i;
                }
            }

            int maxReach = i;
            foreach (int idx in last) {
                if (idx > maxReach) maxReach = idx;
            }

            res[i] = maxReach - i + 1;
        }

        return res;
    }
}
