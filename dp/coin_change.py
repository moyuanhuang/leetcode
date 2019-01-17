# 322. Coin Change
# medium

class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        coins.sort(reverse=True)
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0
        for i in range(1, amount + 1):
            for coin in coins:
                if coin > i:
                    continue
                leftOver = i - coin
                if dp[leftOver] != -1:
                    dp[i] = min(dp[leftOver] + 1, dp[i])
        return dp[amount] if dp[amount] <= amount else -1