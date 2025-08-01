function generate(numRows: number): number[][] {
    const triangle: number[][] = [];
    let prev: number[] = [];

    for (let i = 0; i < numRows; i++) {
        const curr: number[] = [1];

        for (let j = 1; j < i; j++) {
            curr.push(prev[j - 1] + prev[j]);
        }

        if (i > 0) {
            curr.push(1);
        }

        triangle.push(curr);
        prev = curr;
    }

    return triangle;
}
