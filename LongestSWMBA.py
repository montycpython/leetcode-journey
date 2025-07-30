from typing import List

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        max_val = float('-inf')
        longest = curr_len = 0

        for num in nums:
            if num > max_val:
                max_val = num
                curr_len = 1
                longest = 1
            elif num == max_val:
                curr_len += 1
                longest = max(longest, curr_len)
            else:
                curr_len = 0

        return longest
