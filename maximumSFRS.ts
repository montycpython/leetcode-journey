/*Maximum Score From Removing Sub String*/
function maximumGain(s: string, x: number, y: number): number {
    const gain = (first: string, second: string, value: number): ((arr: string[]) => number) => {
        return (arr: string[]) => {
            let top = 0, score = 0;
            for (let i = 0; i < arr.length; i++) {
                if (top > 0 && arr[top - 1] === first && arr[i] === second) {
                    top--;
                    score += value;
                } else {
                    arr[top++] = arr[i];
                }
            }
            arr.length = top;
            return score;
        };
    };

    const arr = s.split('');
    const firstPass = x >= y ? gain('a', 'b', x) : gain('b', 'a', y);
    const secondPass = x >= y ? gain('b', 'a', y) : gain('a', 'b', x);

    const score1 = firstPass(arr);
    const score2 = secondPass(arr);

    return score1 + score2;
}
