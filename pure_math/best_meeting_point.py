# 296. Best Meeting Point
# hard

class Solution:
    def minTotalDistance(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        xs, ys = [], []

        r, c = len(grid), len(grid[0])
        if r == 0:
            return 0

        for i in range(r):
            for j in range(c):
                pt = grid[i][j]
                if pt == 0:
                    continue
                xs.append(i)
                ys.append(j)

        xs.sort()
        ys.sort()
        index = len(xs) // 2
        xMeet, yMeet = xs[index], ys[index]

        distanceSum = 0
        for (x, y) in zip(xs, ys):
            distanceSum += abs(xMeet - x) + abs(yMeet - y)

        return distanceSum
