/**
 * @param {number[][]} fruits
 * @param {number} startPos
 * @param {number} k
 * @return {number}
 */
var maxTotalFruits = function(fruits, startPos, k) {
    let maxFruits = 0;
    let total = 0;
    let left = 0;

    for (let right = 0; right < fruits.length; right++) {
        total += fruits[right][1];

        while (
            left <= right &&
            Math.min(
                Math.abs(startPos - fruits[left][0]) + (fruits[right][0] - fruits[left][0]),
                Math.abs(startPos - fruits[right][0]) + (fruits[right][0] - fruits[left][0])
            ) > k
        ) {
            total -= fruits[left][1];
            left++;
        }

        maxFruits = Math.max(maxFruits, total);
    }

    return maxFruits;
};
