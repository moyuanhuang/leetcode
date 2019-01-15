# 694. Number of Distinct Islands
# medium

class Solution:
    def numDistinctIslands(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        self.rows = len(grid)
        if not self.rows:
            return 0
        self.cols = len(grid[0])

        moves = {
            'u': (0, 1),
            'd': (0, -1),
            'l': (-1, 0),
            'r': (1, 0)
        }
        visited = set()
        distinctIslands = set()

        def helper(curIsland, position):
            x, y = position
            for direction, move in moves.items():
                tempX = x + move[0]
                tempY = y + move[1]
                if tempX < 0 or tempX >= self.rows or tempY < 0 or tempY >= self.cols:
                    continue
                if grid[tempX][tempY] == 0 or (tempX, tempY) in visited:
                    continue

                visited.add((tempX, tempY))
                curIsland = helper(curIsland + direction, (tempX, tempY))
            curIsland += 'b'  # back
            return curIsland
        
        count = 0
        for i in range(self.rows):
            for j in range(self.cols):
                if grid[i][j] == 1 and (i, j) not in visited:
                    visited.add((i, j))
                    island = helper('o', (i, j))
                    if island not in distinctIslands:
                        distinctIslands.add(island)
                        count += 1
        return count
