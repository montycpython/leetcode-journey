public class Solution {
    public int MaxTotalFruits(int[][] fruits, int startPos, int k) {
        int n = fruits.Length;
        int maxFruits = 0;
        int sum = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            sum += fruits[right][1];

            while (left <= right) {
                int leftPos = fruits[left][0];
                int rightPos = fruits[right][0];

                int steps = Math.Min(
                    Math.Abs(startPos - leftPos) + (rightPos - leftPos),
                    Math.Abs(startPos - rightPos) + (rightPos - leftPos)
                );

                if (steps <= k) break;

                sum -= fruits[left][1];
                left++;
            }

            maxFruits = Math.Max(maxFruits, sum);
        }

        return maxFruits;
    }
}
