from typing import List

class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        tree = SegmentTree(baskets)
        unplaced = 0

        for fruit in fruits:
            idx = tree.find_and_remove_leftmost(0, 0, len(baskets) - 1, fruit)
            if idx == -1:
                unplaced += 1

        return unplaced

class SegmentTree:
    def __init__(self, data: List[int]):
        self.n = len(data)
        self.tree = [0] * (4 * self.n)
        self.build(data, 0, 0, self.n - 1)

    def build(self, data: List[int], node: int, l: int, r: int):
        if l == r:
            self.tree[node] = data[l]
            return
        mid = (l + r) // 2
        self.build(data, 2 * node + 1, l, mid)
        self.build(data, 2 * node + 2, mid + 1, r)
        self.tree[node] = max(self.tree[2 * node + 1], self.tree[2 * node + 2])

    def find_and_remove_leftmost(self, node: int, l: int, r: int, val: int) -> int:
        if self.tree[node] < val:
            return -1
        if l == r:
            self.tree[node] = 0
            return l
        mid = (l + r) // 2
        res = self.find_and_remove_leftmost(2 * node + 1, l, mid, val)
        if res == -1:
            res = self.find_and_remove_leftmost(2 * node + 2, mid + 1, r, val)
        self.tree[node] = max(self.tree[2 * node + 1], self.tree[2 * node + 2])
        return res
