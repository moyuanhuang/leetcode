# Shortest Subarray with Sum at Least K
# hard

# 1. remember to push (0, -1) in the beginning to inspect [:i]
from heapq import *

class Solution:
    def shortestSubarray(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        size = len(A)
        sum_till = [0] * size
        heap = []
        heappush(heap, (0, -1))
        shortest = size + 1

        sum_ = 0
        for i in range(size):
            sum_ += A[i]
            sum_till[i] = sum_

        for j in range(size):
            thres = sum_till[j] - K
            while heap and (heap[0][0] <= thres or j - heap[0][1] >= shortest):
                _, i = heappop(heap)
                shortest = min(shortest, j - i)
            heappush(heap, (sum_till[j], j))

        return shortest if shortest <= size else -1

