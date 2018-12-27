# 911. Online Election
# medium

from collections import defaultdict

class TopVotedCandidate(object):

    def __init__(self, persons, times):
        """
        :type persons: List[int]
        :type times: List[int]
        """
        self.times = times
        self.leads = []
        counter = defaultdict(int)
        lead = -1

        for p, t in zip(persons, times):
            counter[p] += 1
            if counter[p] >= counter[lead]:
                lead = p
            self.leads.append(lead)

    def q(self, t):
        """
        :type t: int
        :rtype: int
        """

        # lo, hi = 0, len(self.times) - 1
        # while lo < hi:
        #     mid = (lo + hi) // 2
        #     if t < self.times[mid]:
        #         hi = mid
        #     elif t > self.times[mid]:
        #         lo = mid + 1
        #     else:
        #         lo = mid
        #         break
        # time = self.times[lo]
        # if t <time:
        #     lo -= 1

        # if lo < 0:
        #     return None
        # else:
        #     return self.leads[lo]
        
        # alternatively, we can use bisect
        # The returned insertion point i partitions the array a into two halves so that 
        # all(val <= x for val in a[lo:i]) for the left side and 
        # all(val > x for val in a[i:hi]) for the right side.
        return self.leads[bisect.bisect(self.times, t) - 1]

# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate(persons, times)
# param_1 = obj.q(t)
