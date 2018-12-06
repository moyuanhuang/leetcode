# 54. Spiral Matrix
# medium

class Solution:
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if len(matrix) == 0:
            return []

        r, c = len(matrix), len(matrix[0])

        firstPart = matrix[0]

        for i in range(1, len(matrix)):
            matrix[i][:] = matrix[i][::-1]

        transposedMatrix = [[0] * (r - 1) for i in range(c)]
        for j in range(c):
            for i in range(1, r):
                transposedMatrix[j][i - 1] = matrix[i][j]

        print(transposedMatrix)
        secondPart = self.spiralOrder(transposedMatrix)

        return firstPart + secondPart
