from typing import List

class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        self.max_or = 0
        self.count = 0
        
        # Compute global max OR
        for num in nums:
            self.max_or |= num
        
        def dfs(index: int, current_or: int):
            # Prune paths that can't reach max_or
            if current_or | self.remaining_or[index] < self.max_or:
                return
            if index == len(nums):
                if current_or == self.max_or:
                    self.count += 1
                return
            # Include nums[index]
            dfs(index + 1, current_or | nums[index])
            # Exclude nums[index]
            dfs(index + 1, current_or)

        # Precompute OR of suffixes for pruning
        self.remaining_or = [0] * (len(nums) + 1)
        for i in range(len(nums) - 1, -1, -1):
            self.remaining_or[i] = self.remaining_or[i + 1] | nums[i]
        
        dfs(0, 0)
        return self.count
