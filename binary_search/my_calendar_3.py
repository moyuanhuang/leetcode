# 732. My Calendar III
# hard

import bisect

class MyCalendarThree(object):

    def __init__(self):
        self.nMeetings = []
        self.times = []

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """

        i = bisect.bisect(self.times, start)
        if i > 0 and self.times[i - 1] == start:
            self.nMeetings[i - 1] += 1
        else:
            self.nMeetings.insert(i, 1)
            self.times.insert(i, start)

        j = bisect.bisect(self.times, end)
        if j > 0 and self.times[j - 1] == end:
            self.nMeetings[j - 1] -= 1
        else:
            self.nMeetings.insert(j, -1)
            self.times.insert(j, end)

        maxK = 0
        total = 0
        for n in self.nMeetings:
            total += n
            maxK = max(maxK, total)

        return maxK


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)
