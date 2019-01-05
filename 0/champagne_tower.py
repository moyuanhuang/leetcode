# 799. Champagne Tower
# medium

class Solution(object):
    def champagneTower(self, poured, query_row, query_glass):
        """
        :type poured: int
        :type query_row: int
        :type query_glass: int
        :rtype: float
        """
        tower = [[0] * 101 for i in range(101)]
        tower[0][0] = poured

        for row in range(100):
            for j in range(100):
                amount = tower[row][j]
                if amount > 1:
                    tower[row + 1][j] += (amount - 1) / 2
                    tower[row + 1][j + 1] += (amount - 1) / 2
                    tower[row][j] = 1

        return tower[query_row][query_glass]
