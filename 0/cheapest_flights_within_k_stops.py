# 787. Cheapest Flights Within K Stops
# medium

from collections import defaultdict
from heapq import heappop, heappush

class Solution:
    def findCheapestPrice(self, n, flights, src, dst, K):
        """
        :type n: int
        :type flights: List[List[int]]
        :type src: int
        :type dst: int
        :type K: int
        :rtype: int
        """
        paths = defaultdict(dict)
        for i, j, p in flights:
            paths[i][j] = p

        heap = [(0, src, K + 1)]
        while heap:
            p, i, k = heappop(heap)
            if i == dst:
                return p
            if k > 0:
                for next_stop, price in paths[i].items():
                    heappush(heap, (p + price, next_stop, k - 1))
        return -1
