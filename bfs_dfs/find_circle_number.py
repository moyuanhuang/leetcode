# 547. Friend Circles
# medium

class Solution:
    def findCircleNum(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        def helper(mat, grouped, index):
            grouped.add(index)
            for j in range(len(mat[0])):
                if mat[index][j] and not j in grouped::
                    helper(mat, grouped, j)

        grouped = set()
        n = 0
        rows, cols = len(M), len(M[0])
        for i in range(rows):
            if i in grouped:
                continue
            n += 1
            helper(M, grouped, i)

        return n
