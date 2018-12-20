
# 857. Minimum Cost to Hire K Workers
# hard

from heapq import heappush, heappop
import sys

class Solution:
    def mincostToHireWorkers(self, quality, wage, K):
        """
        :type quality: List[int]
        :type wage: List[int]
        :type K: int
        :rtype: float
        """
        ratioQuality = []
        n = len(quality)
        if n == 0:
            return 0

        for i in range(n):
            w, q = wage[i], quality[i]
            ratio = w / q
            ratioQuality.append((ratio, q))
        ratioQuality.sort()

        minWage = sys.maxsize
        heap = []
        qsum = 0
        for worker in ratioQuality:
            r, q = worker

            qsum += q
            heappush(heap, -q)

            if len(heap) > K:
                q = heappop(heap)
                qsum += q
            if len(heap) == K:
                minWage = min(minWage, r * qsum)

        return minWage
