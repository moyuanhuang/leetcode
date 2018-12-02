# 60. Permutation Sequence
# medium

from math import factorial

class Solution:
    # math O(n) solution
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        digits = [str(i) for i in range(1, n + 1)]
        k -= 1
        result = ''

        x = n
        while x > 0:
            perm_per_group = factorial(x - 1)
            group, index = divmod(k, perm_per_group)

            result += digits[group]
            k = index
            x -= 1
            digits.pop(group)

        return result

    # utilize "Next Permutation", I think this solution is acctually acceptable during interview
    def getPermutation_(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        digits = [i for i in range(1, n +1)]
        m, n = len(digits) - 2, len(digits) - 1
        counter = 1

        while counter < k:
            while m >= 0:
                if digits[m] < digits[m - 1]:
                    break
                m -= 1

            while digits[n] < digits[m]:
                n -= 1

            digits[m], digits[n] = digits[n], digits[m]

            digits[m + 1:] = digits[m + 1:][::-1]

            counter += 1

        result = [str(i) for i in digits]
        return ''.join(result)
