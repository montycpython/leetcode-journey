from typing import List

class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        result = set()
        curr = set()

        for num in arr:
            next_set = {num}
            for val in curr:
                next_set.add(val | num)
            curr = next_set
            result.update(curr)

        return len(result)
