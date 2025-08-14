class Solution: #0ms, 17.71MB
    def largestGoodInteger(self, num: str) -> str:
        p = ""
        for i in range(10):
            j = str(i)*3
            if j in num and j > p:
                p = j
        return p

class Solution1: #0ms, 17.65MB
    def largestGoodInteger(self, num: str) -> str:
        p = ""
        for i in set(num):
            j = i*3
            if j in num and j > p:
                p = j
        return p

class Solution2: #7ms, 17.98MB
    def largestGoodInteger(self, num: str) -> str:
        x, y, p = 0, 3, ""
        while y <= len(num):
            a = num[x: y]
            if len(set(a)) == 1 and a > p:
                p = a
            x +=1; y+=1
        return p

class Solution3: #3ms, 17.57MB
    def largestGoodInteger(self, num: str) -> str:
        p = ""
        for i in range(len(num) - 2):
            if num[i] == num[i+1] == num[i+2]:
                if num[i] > p[:1]:  # Compare only first digit since all are equal
                    p = num[i] * 3
        return p
