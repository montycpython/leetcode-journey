public class Solution {
    public int NumOfUnplacedFruits(int[] fruits, int[] baskets) {
        int unplaced = 0;

        for (int i = 0; i < fruits.Length; i++) {
            bool placed = false;
            for (int j = 0; j < baskets.Length; j++) {
                if (baskets[j] >= fruits[i]) {
                    baskets[j] = -1; // Mark basket as used
                    placed = true;
                    break;
                }
            }
            if (!placed) unplaced++;
        }

        return unplaced;
    }
}
