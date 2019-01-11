# 503. Next Greater Element II
# medium

from heapq import heappop, heappush

class Solution:
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        length = len(nums)
        result = [-1] * length

        heap = []
        for i, n in enumerate(nums):
            while heap and heap[0][0] < n:
                _, index = heappop(heap)
                result[index] = n
            heappush(heap, (n, i))

        for i, n in enumerate(nums):
            while heap and heap[0][0] < n:
                _, index = heappop(heap)
                result[index] = n
        return result
            