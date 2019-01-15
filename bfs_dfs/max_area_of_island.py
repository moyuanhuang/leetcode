# 695. Max Area of Island
# medium

class Solution:
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        self.rows = len(grid)
        if not grid:
            return 0
        self.cols = len(grid[0])
        
        moves = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        visited = set()
        maxArea = 0

        def helper(curArea, position):
            x_, y_ = position
            for direction in moves:
                x = x_ + direction[0]
                y = y_ + direction[1]
                if x < 0 or x >= self.rows or y < 0 or y >= self.cols:
                    continue
                if grid[x][y] == 0 or (x, y) in visited:
                    continue
                visited.add((x, y))
                curArea = helper(curArea + 1, (x, y))
            return curArea
        
        for i in range(self.rows):
            for j in range(self.cols):
                if grid[i][j] == 0 or (i, j) in visited:
                    continue
                visited.add((i, j))
                area = helper(1, (i, j))
                maxArea = max(maxArea, area)
        return maxArea
                