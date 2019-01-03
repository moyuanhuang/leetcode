# 769. Max Chunks To Make Sorted
# medium

class Solution:
    def maxChunksToSorted(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        got, need = set(), set()

        maxChunks = 0
        for index in range(len(arr)):
            val = arr[index]

            got.add(val)
            if val in need:
                need.remove(val)
            if val != index and index not in got:
                need.add(index)
                
            if len(need) == 0:
                maxChunks += 1
                got, need = set(), set()

        return maxChunks