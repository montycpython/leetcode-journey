#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    // Allocate space for the triangle
    int** triangle = (int**)malloc(numRows * sizeof(int*));
    int* columnSizes = (int*)malloc(numRows * sizeof(int));

    for (int i = 0; i < numRows; ++i) {
        triangle[i] = (int*)malloc((i + 1) * sizeof(int));
        columnSizes[i] = i + 1;

        triangle[i][0] = 1;
        triangle[i][i] = 1;

        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    *returnSize = numRows;
    *returnColumnSizes = columnSizes;
    return triangle;
}
