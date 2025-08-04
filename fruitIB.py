from typing import List

class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        count = {}
        left = 0
        max_len = 0

        for right, fruit in enumerate(fruits):
            count[fruit] = count.get(fruit, 0) + 1

            while len(count) > 2:
                left_fruit = fruits[left]
                count[left_fruit] -= 1
                if count[left_fruit] == 0:
                    del count[left_fruit]
                left += 1

            window_len = right - left + 1
            if window_len > max_len:
                max_len = window_len

        return max_len
