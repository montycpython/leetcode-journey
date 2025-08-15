class Solution: #321ms, 18.86MB; time: O(n^2) quadratic, space: O(n) linear
    def makeFancyString(self, s: str) -> str:
        for letter in set(s):
            while letter * 3 in s:
                s = s.replace(letter * 3, letter * 2)
        return s

class Solution1: #355ms, 19.31MB; time: O(n^2) quadratic, space: O(n) linear
  def makeFancyString(self, s: str) -> str:
      res = "" #python strings are immutable, hence O(n^2)
      for char in s:
          if len(res) >= 2 and res[-1] == res[-2] == char:
              continue
          res += char
      return res

class Solution2: #336ms, 19.65MB; time: O(n) linear, space: O(n) linear
  def makeFancyString(self, s: str) -> str:
      res = [] 
      for char in s:
          if len(res) >= 2 and res[-1] == res[-2] == char:
              continue
          res.append(char)
      return "".join(res)

class Solution3: #239ms, 19.58Mb
    def makeFancyString(self, s: str) -> str:
        ans = []
        last = s[0]
        ans.append(last)
        count = 1
        for i in range(1, len(s)):
            if s[i] == last:
                count += 1
                if count < 3:
                    ans.append(s[i])
            else:
                last = s[i]
                count = 1
                ans.append(s[i])
        return "".join(ans)
