class Solution:
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        ceil = int((c/2) ** 0.5) + 1
        for i in range(ceil):
            b_sq = c - i ** 2
            if (b_sq ** 0.5).is_integer():
                return True
        return False

