# 312. Burst Balloons
# hard

class Solution:
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = [1] + nums + [1]
        length = len(nums)
        dp = [[0] * length for i in range(length)] 

        for l in range(1, length - 2):
            for i in range(1, length - l - 1):
                j = i + l - 1
                for k in range(i, j + 1):
                    dp[i][j] = max(dp[i][j], nums[k] * nums[i - 1] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j])

        return dp[1][length]
