# 759. Employee Free Time
# hard

# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

import bisect

class Solution(object):
    def employeeFreeTime(self, schedule):
        """
        :type schedule: List[List[Interval]]
        :rtype: List[Interval]
        """
        nEmployee = len(schedule)
        if nEmployee == 0: return []
        result = schedule[0][:]

        for employee in schedule[1:]:
            for interval in employee:
                startTimes = [intv.start for intv in result]
                index = bisect.bisect(startTimes, interval.start)
                # print(startTimes, interval.start, index)

                while index < len(result) and result[index].start <= interval.end:
                    interval.end = max(interval.end, result[index].end)
                    result.pop(index)

                if index > 0 and result[index - 1].end >= interval.start:
                    interval.start = result[index- 1].start
                    interval.end = max(interval.end, result[index - 1].end)
                    result.pop(index - 1)
                    index -= 1
                result.insert(index, interval)
        
        ret = []
        for i in range(len(result) - 1):
            new_intv = Interval(result[i].end, result[i + 1].start)
            ret.append(new_intv)
        return ret