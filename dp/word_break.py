# 139. Word Break
# medium

class Solution:
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        dp = [False] * (len(s) + 1)
        dp[0] = True

        for end in range(len(s)):
            for start in range(0, end + 1):
                if dp[start] and (s[start:end + 1] in wordDict):
                    dp[end + 1] = True
                    break

        return dp[-1]
            
