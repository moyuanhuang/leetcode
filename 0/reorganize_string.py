#  767. Reorganize String
#  medium

from collections import defaultdict
from heapq import heappop, heappush

class Solution(object):
    def reorganizeString(self, S):
        """
        :type S: str
        :rtype: str
        """
        length = len(S)
        counter = defaultdict(int)
        heap = []
        result = [0] * length

        for ch in S:
            counter[ch] += 1

        for ch, count in counter.items():
            heappush(heap, (-count, ch))
        if -heap[0][0] > (length + 1) // 2:
            return ""

        index = 0
        
        while heap:
            print(heap)
            count, ch = heappop(heap)
            count = -count
            while count:
                result[index] = ch
                index += 2
                if index >= length:
                    index = 1
                count -= 1
        print(result)
        return ''.join(result)
