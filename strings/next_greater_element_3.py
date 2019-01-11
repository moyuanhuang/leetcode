# 556. Next Greater Element III
# medium

class Solution:
    def nextGreaterElement(self, n):
        """
        :type n: int
        :rtype: int
        """
        n = list(str(n))

        length = len(n)
        i = length - 2
        while i >= 0 and n[i] >= n[i + 1]:
            i -= 1
        if i < 0:
            return -1

        j = length - 1
        while j > i and n[j] <= n[i]:
            j -= 1
        n[i], n[j] = n[j], n[i]

        secondPart = n[i + 1:]
        secondPart.reverse()
        n[i + 1:] = secondPart[:]
        res = int(''.join(n))
        return res if res <= (1 << 31) -1 else -1