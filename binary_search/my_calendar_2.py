# 731. My Calendar II
# medium

import bisect

class MyCalendarTwo(object):

    def __init__(self):
        self.nMeetings = []
        self.times = []

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """
        nMeetings, times = self.nMeetings[:], self.times[:]

        i = bisect.bisect(times, start)
        if i > 0 and times[i - 1] == start:
            nMeetings[i - 1] += 1
        else:
            nMeetings.insert(i, 1)
            times.insert(i, start)

        j = bisect.bisect(times, end)
        if j > 0 and times[j - 1] == end:
            nMeetings[j - 1] -= 1
        else:
            nMeetings.insert(j, -1)
            times.insert(j, end)

        total = 0
        for n in nMeetings:
            total += n
            if total > 2:
                return False

        self.nMeetings = nMeetings[:]
        self.times = times[:]
        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)
