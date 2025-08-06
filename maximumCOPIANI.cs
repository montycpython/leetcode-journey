public class Solution {
    public int MaximumCount(int[] nums) {
        int firstNonNegative = LowerBound(nums, 0); // index of first 0 or positive
        int firstPositive = LowerBound(nums, 1);    // index of first strictly positive

        int negCount = firstNonNegative;
        int posCount = nums.Length - firstPositive;

        return Math.Max(negCount, posCount);
    }

    private int LowerBound(int[] nums, int target) {
        int left = 0, right = nums.Length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
}
