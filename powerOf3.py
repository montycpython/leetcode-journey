class Solution: #space: 17.58MB time: 48ms
    def isPowerOfThree(self, n: int) -> bool:
        po3 = [3 ** i for i in range(20)]
        return n > 0 and n in po3

class Solution2: #space: 18.04MB time: 5ms
  def isPowerOfThree(self, n: int) -> bool:
    if n <= 0:
      return False
    while n % 3 == 0:
        n //= 3
    return n == 1

class Solution3:
    def isPowerOfThree(self, n: int) -> bool: #space: 17.68MB time: 8ms
        return n > 0 and 1162261467 % n == 0 #largest power of 3 that fits into a 32 bit signed integer

class Solution4:
    def isPowerOfThree(self, n: int) -> bool: #space: 17.60MB time: 3ms
        return n > 0 and (3**19) % n == 0 #largest power of 3 that fits into a 32 bit signed integer

import dis #inspect bytecode using dis

dis.dis(lambda n: n > 0 and 1162261467 % n == 0)
dis.dis(lambda n: n > 0 and (3**19) % n == 0)

import timeit

print(timeit.timeit("n > 0 and 1162261467 % n == 0", globals={"n": 27}, number=10**6))
print(timeit.timeit("n > 0 and (3**19) % n == 0", globals={"n": 27}, number=10**6))
