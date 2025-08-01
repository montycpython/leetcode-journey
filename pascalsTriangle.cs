public class Solution {
    public IList<IList<int>> Generate(int numRows) {
        var triangle = new List<IList<int>>();

        for (int row = 0; row < numRows; row++) {
            var currentRow = new List<int>();
            currentRow.Add(1); // First element is always 1

            for (int col = 1; col < row; col++) {
                int sum = triangle[row - 1][col - 1] + triangle[row - 1][col];
                currentRow.Add(sum);
            }

            if (row > 0)
                currentRow.Add(1); // Last element is also 1

            triangle.Add(currentRow);
        }

        return triangle;
    }
}
