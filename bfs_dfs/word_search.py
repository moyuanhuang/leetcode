# 79. Word Search
# medium

class Solution:
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        self.rows, self.cols = len(board), len(board[0])

        def search(i, j, used, index):
            if index == len(word):
                return True

            options = [(i, j - 1), (i - 1, j), (i, j + 1), (i + 1, j)]
            for opt in options:
                ti, tj = opt[0], opt[1]
                if ti < 0 or tj < 0 or ti >= self.rows or tj >= self.cols:
                    continue
                if (opt in used) or board[ti][tj] != word[index]:
                    continue
                used.add(opt)

                found = search(ti, tj, used, index + 1)
                if found:
                    # print("board[%d][%d] = %c == %c" % (ti, tj, board[ti][tj], word[index]))
                    return True
                used.remove(opt)

        if not word:
            return True
        if not board:
            return False

        for i in range(self.rows):
            for j in range(self.cols):
                if board[i][j] == word[0]:
                    used = set()
                    used.add((i, j))
                    exist = search(i, j, mys, 1)
                    if exist:
                        return True
        return False
