class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0:
            return []

        triangle = [[1]]
        for i in range(1, numRows):
            prev_row = [0] + triangle[-1] + [0]
            current_row = [prev_row[j] + prev_row[j+1] for j in range(i + 1)]
            triangle.append(current_row)
        return triangle
