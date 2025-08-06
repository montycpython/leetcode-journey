/**
 * @param {number[]} fruits
 * @param {number[]} baskets
 * @return {number}
 */
var numOfUnplacedFruits = function(fruits, baskets) {
    const n = baskets.length;
    
    // For the constraint n <= 10^5, we need an O(n log n) solution
    // Use a segment tree approach with coordinate compression
    
    // Create a max segment tree where tree[i] represents the maximum capacity
    // available in the range, and we can query/update efficiently
    
    class SegmentTree {
        constructor(arr) {
            this.n = arr.length;
            this.tree = new Array(4 * this.n);
            this.arr = [...arr];
            this.build(0, 0, this.n - 1);
        }
        
        build(node, start, end) {
            if (start === end) {
                this.tree[node] = this.arr[start];
            } else {
                const mid = Math.floor((start + end) / 2);
                this.build(2 * node + 1, start, mid);
                this.build(2 * node + 2, mid + 1, end);
                this.tree[node] = Math.max(this.tree[2 * node + 1], this.tree[2 * node + 2]);
            }
        }
        
        // Find leftmost index where arr[index] >= value and update it to 0
        queryAndUpdate(node, start, end, value) {
            if (this.tree[node] < value) {
                return -1; // No suitable basket in this range
            }
            
            if (start === end) {
                // Found the position
                this.tree[node] = 0;
                this.arr[start] = 0;
                return start;
            }
            
            const mid = Math.floor((start + end) / 2);
            
            // Try left side first (leftmost priority)
            const leftResult = this.queryAndUpdate(2 * node + 1, start, mid, value);
            if (leftResult !== -1) {
                // Update parent node
                this.tree[node] = Math.max(this.tree[2 * node + 1], this.tree[2 * node + 2]);
                return leftResult;
            }
            
            // Try right side
            const rightResult = this.queryAndUpdate(2 * node + 2, mid + 1, end, value);
            if (rightResult !== -1) {
                // Update parent node
                this.tree[node] = Math.max(this.tree[2 * node + 1], this.tree[2 * node + 2]);
                return rightResult;
            }
            
            return -1;
        }
        
        findAndRemoveLeftmost(value) {
            return this.queryAndUpdate(0, 0, this.n - 1, value);
        }
    }
    
    const segTree = new SegmentTree(baskets);
    let unplacedCount = 0;
    
    for (const fruit of fruits) {
        const position = segTree.findAndRemoveLeftmost(fruit);
        if (position === -1) {
            unplacedCount++;
        }
    }
    
    return unplacedCount;
};
