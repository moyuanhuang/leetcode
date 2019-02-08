# 647. Palindromic Substrings
# medium

class Solution:
    def countSubstrings(self, s: 'str') -> 'int':
        if not s:
            return 0
        
        def helper(left, right):
            if left < 0 or right >= len(s):
                return
            if s[left] != s[right]:
                return
            self.count += 1
            helper(left - 1, right + 1)

        self.count = 0
        for i in range(len(s)):        
            helper(i, i)
            helper(i, i + 1)
        return self.count
