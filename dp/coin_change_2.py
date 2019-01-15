# 518. Coin Change 2
# medium

# Classic knapsack problem
# dp[i][amount]: number of combinations we can get using first i types of coins for amount

class Solution:
    def change(self, amount, coins):
        """
        :type amount: int
        :type coins: List[int]
        :rtype: int
        """
        if amount == 0:
            return 1
        if not coins:
            return 0
        dp = [0] * (amount + 1)
        dp[0] = 1

        for i in range(len(coins)):
            coin = coins[i]
            for m in range(1, amount + 1):
                if coin <= m:
                    dp[m] += dp[m - coin]
        return dp[amount]