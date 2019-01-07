# 845. Longest Mountain in Array
# medium

# 3 pass can be easily achieved
# 1 pass solution is harder
import sys

class Solution:
    def longestMountain(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        length = len(A)
        down, up = 0, 0
        maxLen = 0
        for i in range(1, length):
            if (down and A[i - 1] < A[i]) or A[i - 1] == A[i]:
                up = down = 0
            down += A[i] < A[i - 1]
            up += A[i] > A[i - 1]
            if up and down:
                maxLen = max(maxLen, up + down + 1)
        return maxLen
