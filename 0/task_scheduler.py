# 621. Task Scheduler
# medium

from collections import defaultdict
class Solution:
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        counter = [0] * 26
        for t in tasks:
            counter[ord(t) - ord('A')] += 1

        counter.sort()

        i = 25
        while i >= 0 and counter[25] == counter[i]:
            i -= 1

        return max(len(tasks), (counter[25] - 1) * (n + 1) + 25 - i)
