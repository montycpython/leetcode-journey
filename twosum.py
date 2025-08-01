from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        lookup = {}  # Stores value: index pairs
        for i, num in enumerate(nums):
            complement = target - num
            if complement in lookup:
                return [lookup[complement], i]
            lookup[num] = i
        
