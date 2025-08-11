class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        mod = 10**9 + 7

        # Extract powers of 2 from binary representation of n
        powers = [1 << i for i in range(31) if (n >> i) & 1]

        # Precompute prefix products
        prefix = [1] * len(powers)
        for i, val in enumerate(powers):
            prefix[i] = (prefix[i - 1] * val) % mod if i else val

        # Answer queries using prefix products (no modular inverse)
        return [
            prefix[r] if l == 0 else (prefix[r] * pow(prefix[l - 1], mod - 2, mod)) % mod
            for l, r in queries
        ]
