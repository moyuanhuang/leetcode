# 57. Insert Interval
# hard

# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        sorted(intervals)
        length = len(intervals)

        start = newInterval.start
        end = newInterval.end
        res = []
        i = 0
        while i < length:
            if end >= intervals[i].start:
                if start > intervals[i].end:
                    res.append(intervals[i])
                else:
                    newInterval.start = min(newInterval.start, intervals[i].start)
                    newInterval.end = max(newInterval.end, intervals[i].end)
            else:
                break
            i += 1
        res.append(newInterval)
        res.extend(intervals[i:])
        return res

