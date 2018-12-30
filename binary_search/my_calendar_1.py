# 729. My Calendar I
# medium

import bisect

class MyCalendar(object):

    def __init__(self):
        self.eventStart = []
        self.events = {}
        

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """
        i = bisect.bisect(self.eventStart, start)
        if i > 0:
            prevStart = self.eventStart[i - 1]
            prevEnd = self.events[prevStart]
            if start < prevEnd:
                return False

        if i < len(self.eventStart):
            nextStart = self.eventStart[i]
            if end > nextStart:
                return False

        self.eventStart.insert(i, start)
        self.events[start] = end

        return True

# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)
