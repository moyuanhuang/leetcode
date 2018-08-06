# 373. Find K Pairs with Smallest Sums
# medium
# use heap. similar to 378. 把nums2竖过来，nums1的每一列都是一串递增的sums

from heapq import *

class Solution:
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        pq = []
        if not(len(nums1) and len(nums2)):
            return []

        res = []
        for col in range(len(nums1)):
            summ = nums1[col] + nums2[0]
            heappush(pq, (summ, col, 0))
        count = 0
        while len(pq):
            if count == k:
                break
            _, i1, i2 = heappop(pq)
            pair = [nums1[i1], nums2[i2]]
            res.append(pair)
            count += 1
            if i2 + 1 < len(nums2):
                heappush(pq, (nums1[i1] + nums2[i2+1], i1, i2+1))
        return res

