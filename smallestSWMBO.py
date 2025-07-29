from typing import List

class Solution: #smallest subarrays with maximum bitwise or
    def smallestSubarrays(self, nums: List[int]) -> List[int]:
        n = len(nums)
        last_seen = [-1] * 32
        answer = [1] * n

        for i in range(n - 1, -1, -1):
            for bit in range(32):
                if (nums[i] >> bit) & 1:
                    last_seen[bit] = i
            furthest = i
            for bit in range(32):
                if last_seen[bit] != -1:
                    furthest = max(furthest, last_seen[bit])
            answer[i] = furthest - i + 1

        return answer
