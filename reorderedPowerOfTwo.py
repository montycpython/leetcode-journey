class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        def digit_signature(x: int) -> tuple:
            sig = [0] * 10
            while x:
                sig[x % 10] += 1
                x //= 10
            return tuple(sig)

        target = digit_signature(n)
        for i in range(31):
            if digit_signature(1 << i) == target:
                return True
        return False
