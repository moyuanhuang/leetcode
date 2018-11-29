# 265. Paint House II
# hard

import sys

class Solution:
    # optimal solution, O(N * K), in-place
    def minCostII(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
        # We just need (lowest_cost, lowest_color) and second_lowest_cost from the previous house!!!
        n_houses = len(costs)
        if n_houses == 0:
            return 0

        n_colors = len(costs[0])

        for i in range(1, n_houses):
            optimal = min(costs[i - 1])
            index = costs[i - 1].index(optimal)
            sub_optimal = min(costs[i - 1][:index] + costs[i - 1][index + 1:])

            for j in range(n_colors):
                if j == index:
                    costs[i][j] += sub_optimal
                else:
                    costs[i][j] += optimal

        return min(costs[n_houses - 1])

    # O(N*K*K) solution, beat 10%
    def minCostII_(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
        n_houses = len(costs)

        if n_houses == 0:
            return 0

        n_colors = len(costs[0])
        dp = [[0] * (n_houses + 1) for i in range(n_colors)]

        for i in range(n_houses):
            for color in range(n_colors):
                # compute min cost to print house i with color
                tmp = sys.maxsize
                for c in range(n_colors):
                    # can't be the same as previous house UNLESS i = 0
                    if i > 0 and c == color:
                        continue
                    tmp = min(tmp, dp[c][i] + costs[i][color])
                dp[color][i + 1] = tmp

        min_cost = sys.maxsize
        for color in range(n_colors):
            min_cost = min(min_cost, dp[color][n_houses])
        return min_cost
