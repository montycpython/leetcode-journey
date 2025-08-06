public class Solution {
    public bool IsPalindrome(int x) {
        // Negative numbers and numbers ending in 0 (but not 0 itself) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // For even digit count: x == reversedHalf
        // For odd digit count: x == reversedHalf / 10
        return x == reversedHalf || x == reversedHalf / 10;
    }
}
