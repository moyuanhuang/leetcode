# 378. Kth Smallest Element in a Sorted Matrix
# medium
# 2 possible solution:
# 1. heap with n_cols elements
# 2. binary search

from heapq import *

class Solution:
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        pq = []
        rows, cols = len(matrix), len(matrix[0])
        for i in range(cols):
            heappush(pq, (matrix[0][i], 0, i))

        count = 0
        while True:
            x, i, j = heappop(pq)
            count += 1
            if count == k:  return x
            if i + 1 < rows:
                heappush(pq, (matrix[i+1][j], i+1, j))

    # binary search solution, use 'range' as a search space instead of 'index'
    # a little hard to understand
    def kthSmallest(self, matrix, k):
        rows, cols = len(matrix), len(matrix[0])
        lo, hi = matrix[0][0], matrix[rows-1][cols-1]
        while lo < hi:
            mid = (lo + hi) // 2
            count = 0
            for i in range(rows):
                j = 0
                while j < cols and matrix[i][j] <= mid:
                    j += 1
                    count += 1
            if count >= k:
                hi = mid
            else:
                lo = mid + 1
        return lo

