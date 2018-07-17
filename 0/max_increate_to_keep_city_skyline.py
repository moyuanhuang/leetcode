# 807. Max Increase to Keep City Skyline
# medium

import numpy as np

class Solution(object):
    def maxIncreaseKeepingSkyline(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid:
            return 0
        rows, cols = np.asarray(grid).shape
        vertical = np.max(grid, axis=0)
        horizontal = np.max(grid, axis=1)

        res = 0
        for i in range(rows):
            for j in range(cols):
                res += min(vertical[j], horizontal[i]) - grid[i][j]
        return int(res)

