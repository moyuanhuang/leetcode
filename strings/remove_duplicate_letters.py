# 316. Remove duplicate letters
# hard
# 1. store the index of last occurrence of each letter, as "the last chance to keep this letter"
# 2. divide the string by those indexes
# 3. python char <-> int: ord() and chr()

from heapq import *

class Solution:
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        last_occ = {}
        res = ""
        length = len(s)
        
        for i in range(length):
            last_occ[s[i]] = i
        heap = []
        for k, v in last_occ.items():
            heappush(heap, v)

        start = 0
        used = set()
        while len(heap):
            end = nsmallest(1, heap)[0]
            smallest = chr(ord('z') + 1)
            for i in range(start, end + 1):
                if s[i] in used:
                    continue
                if s[i] < smallest:
                    smallest = s[i]
                    next_start = i + 1

            res += smallest
            self.findAndPop(heap, last_occ[smallest])
            used.add(smallest)
            start = next_start

        return res
    
    # self implemented pq.remove(elem)
    def findAndPop(self, heap, index):
        temp = []
        while len(heap):
            elem = heappop(heap)
            if elem == index:
                break
            temp.append(elem)
        for elem in temp:
            heappush(heap, elem)

