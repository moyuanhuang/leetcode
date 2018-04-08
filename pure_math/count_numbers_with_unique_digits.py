# 357. Count Numbers with Unique Digits
# medium
# 排列选择问题

class Solution:
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        count = 1
        if n == 0:
            return count
        for i in range(1, n + 1):
            if i > 10:
                return count
            count += 9 * self.permutation(9, i - 1)
        return count

    def permutation(self, n, k):
        if k == 0:
            return 1
        return n * self.permutation(n - 1, k - 1)
