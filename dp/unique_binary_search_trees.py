# 96. Unique Binary Search Trees
# medium

class Solution:
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [0] * (n + 1)
        dp[0] = 1

        for i in range(1, n + 1):
            for left in range(i):
                # print(dp, i, left, i - left - 1)
                dp[i] += dp[left] * dp[i - left - 1]

        return dp[n]
