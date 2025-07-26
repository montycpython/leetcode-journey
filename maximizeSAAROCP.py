from typing import List

class Solution:
    def maxSubarrays(self, n: int, conflictingPairs: List[List[int]]) -> int:
        # conflicts[r] := left endpoints that conflict with subarrays ending at r
        conflicts = [[] for _ in range(n + 1)]
        for a, b in conflictingPairs:
            conflicts[max(a, b)].append(min(a, b))

        validSubarrays = 0
        gains = [0] * (n + 1)
        maxLeft = 0
        secondMaxLeft = 0

        for right in range(1, n + 1):
            for left in conflicts[right]:
                if left > maxLeft:
                    secondMaxLeft = maxLeft
                    maxLeft = left
                elif left > secondMaxLeft:
                    secondMaxLeft = left

            # Subarrays [maxLeft + 1 .. right] to [right .. right] are valid
            validSubarrays += right - maxLeft

            # If we remove maxLeft, we gain subarrays from [secondMaxLeft + 1 .. right] to [maxLeft .. right]
            if maxLeft > 0:
                gains[maxLeft] += maxLeft - secondMaxLeft

        return validSubarrays + max(gains)
