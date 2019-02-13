# 279. Perfect Squares
# medium

class Solution:
    def numSquares(self, n: 'int') -> 'int':
        cnts = [n] * (n + 1)
        cnts[0] = 0
        for i in range(1, n + 1):
            for j in range(1, int(math.sqrt(i)) + 1):
                cnts[i] = min(cnts[i], cnts[i - j ** 2] + 1)
        return cnts[n]
