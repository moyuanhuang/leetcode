# 289. Game of Life
# medium

class Solution:
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        DYING = 2
        KEEPS_ALIVE = 3
        BECOMES_ALIVE = 4
        KEEPS_DEAD = 5

        def currentValue(state):
            if state == 1 or state == DYING or state == KEEPS_ALIVE:
                return 1
            if state == 0 or state == BECOMES_ALIVE or state == KEEPS_DEAD:
                return 0

        def nextValue(state):
            if state == DYING or state == KEEPS_DEAD:
                return 0
            if state == BECOMES_ALIVE or state == KEEPS_ALIVE:
                return 1

        def countLiveNeighbors(x, y):
            n = 0
            for i in range(x - 1, x + 2):
                for j in range(y - 1, y + 2):
                    if i == x and j == y:
                        continue
                    if i < 0 or j < 0 or i >= self.r or j >= self.c:
                        continue

                    n += currentValue(board[i][j])
            return n

        self.r, self.c = len(board), len(board[0])

        for i in range(self.r):
            for j in range(self.c):
                live_neighbors = countLiveNeighbors(i, j)
                if live_neighbors < 2 or live_neighbors > 3:
                    if board[i][j] == 0:
                        board[i][j] = KEEPS_DEAD
                    else:
                        board[i][j] = DYING
                elif live_neighbors == 3:
                    if board[i][j] == 0:
                        board[i][j] = BECOMES_ALIVE
                    else:
                        board[i][j] = KEEPS_ALIVE
                else:
                    if board[i][j] == 0:
                        board[i][j] = KEEPS_DEAD
                    else:
                        board[i][j] = KEEPS_ALIVE

        for i in range(self.r):
            for j in range(self.c):
                board[i][j] = nextValue(board[i][j])

        return
