class Solution:
    def minCost(self, basket1: list[int], basket2: list[int]) -> int:
        # Count all fruits and find minimum cost  
        counts = {}
        for fruit in basket1 + basket2:
            counts[fruit] = counts.get(fruit, 0) + 1
        
        min_cost = min(counts.keys())
        
        # Check if solution is possible
        for count in counts.values():
            if count % 2 != 0:
                return -1
        
        # Count fruits in basket1
        counts1 = {}
        for fruit in basket1:
            counts1[fruit] = counts1.get(fruit, 0) + 1
        
        # Find all fruits that need to be moved from basket1
        # (both excess and deficit contribute to moves needed)
        moves_needed = []
        
        for fruit_cost, total_count in counts.items():
            count_in_b1 = counts1.get(fruit_cost, 0)
            target_count = total_count // 2
            
            imbalance = abs(count_in_b1 - target_count)
            if imbalance > 0:
                moves_needed.extend([fruit_cost] * imbalance)
        
        # We need to move half of these fruits (the other half automatically balances)
        moves_needed.sort()
        num_moves = len(moves_needed) // 2
        
        total_cost = 0
        double_min_cost = 2 * min_cost
        
        for i in range(num_moves):
            total_cost += min(moves_needed[i], double_min_cost)
        
        return total_cost
