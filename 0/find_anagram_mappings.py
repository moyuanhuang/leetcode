# 760. Find Anagram Mappings
# easy

from collections import defaultdict
class Solution:
    def anagramMappings(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        my_map = defaultdict(list)
        for i in range(len(B)):
            my_map[B[i]].append(i)
        res = []

        for n in A:
            index = my_map[n].pop(0)   
            res.append(index)
        return res

