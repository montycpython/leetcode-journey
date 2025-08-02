/**
 * @param {number[]} basket1
 * @param {number[]} basket2
 * @return {number}
 */
var minCost = function(basket1, basket2) {
    const freq = new Map();
    let minFruit = Infinity;

    // Count net frequency difference and track global minimum fruit cost
    for (let i = 0; i < basket1.length; i++) {
        const a = basket1[i], b = basket2[i];
        freq.set(a, (freq.get(a) || 0) + 1);
        freq.set(b, (freq.get(b) || 0) - 1);
        minFruit = Math.min(minFruit, a, b);
    }

    const excess = [];

    for (const [val, count] of freq.entries()) {
        if (count % 2 !== 0) return -1;
        const half = Math.abs(count) / 2;
        for (let i = 0; i < half; i++) excess.push(val);
    }

    if (excess.length === 0) return 0;

    excess.sort((a, b) => a - b);

    let cost = 0;
    const swaps = excess.length / 2;
    for (let i = 0; i < swaps; i++) {
        cost += Math.min(excess[i], 2 * minFruit);
    }

    return cost;
};
