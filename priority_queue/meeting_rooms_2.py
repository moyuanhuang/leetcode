# 253. Meeting Rooms II
# medium

# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

from operator import attrgetter
from heapq import heappush, heappop

class Solution:
    # just +1 for start, -1 for end
    def minMeetingRooms(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        heap = []
        for interval in intervals:
            start, end = interval
            heappush(heap, (start, 1))
            heappush(heap, (end, -1))

        maxRoom = 0
        counter = 0
        while heap:
            _, diff = heappop(heap)
            counter += diff
            maxRoom = max(maxRoom, counter)

        return maxRoom

    # unecessary dumb solution
    def minMeetingRooms_(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        pq = []
        max_room = 0
        intervals.sort(key=attrgetter('start', 'end'))

        for interval in intervals:
            start, end = interval.start, interval.end
            if len(pq) == 0:
                heappush(pq, end)
                continue

            if start >= pq[0]:
                max_room = max(max_room, len(pq))
                while len(pq) and pq[0] <= start:
                    heappop(pq)
                heappush(pq, end)
            else:
                heappush(pq, end)

        return max(max_room, len(pq))
