from typing import List

class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        count = 0
        # Remove consecutive duplicates to simplify comparisons
        filtered = [nums[0]]
        for num in nums[1:]:
            if num != filtered[-1]:
                filtered.append(num)

        # Check each middle element for hill or valley
        for i in range(1, len(filtered) - 1):
            if filtered[i] > filtered[i - 1] and filtered[i] > filtered[i + 1]:
                count += 1  # Hill
            elif filtered[i] < filtered[i - 1] and filtered[i] < filtered[i + 1]:
                count += 1  # Valley

        return count
