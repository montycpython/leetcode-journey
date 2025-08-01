import java.util.ArrayList;
import java.util.List;

public class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> triangle = new ArrayList<>(numRows);

        // Buffers for previous and current rows
        List<Integer> prev = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();

        for (int i = 0; i < numRows; i++) {
            curr.clear();
            curr.add(1); // First element is always 1

            for (int j = 1; j < i; j++) {
                curr.add(prev.get(j - 1) + prev.get(j));
            }

            if (i > 0) {
                curr.add(1); // Last element is always 1
            }

            // Add a copy of the current row to the triangle
            triangle.add(new ArrayList<>(curr));

            // Swap buffers
            List<Integer> temp = prev;
            prev = curr;
            curr = temp;
        }

        return triangle;
    }
}
