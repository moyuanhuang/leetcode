# 750. Number Of Corner Rectangles
# medium

from collections import defaultdict

class Solution:
    def countCornerRectangles(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        r = len(grid):
        if r <= 1:
            return 0
        cols = len(grid[0])

        basesCount = defaultdict(int)
        count = 0
        for row in grid:
            for i in range(cols):
                if row[i] == 0:
                    continue
                for j in range(i + 1, cols):
                    if row[j] == 0:
                        continue
                    base = (i, j)
                    count += basesCount[base]
                    basesCount[base] += 1
        return count