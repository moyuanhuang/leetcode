# 128. Longest Consecutive Sequence
# hard

class Solution:
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # not as hard as I thought
        numsSet = set(nums)
        maxLength = 0

        for x in numsSet:
            if x - 1 not in numsSet:
                length = 0
                temp = x
                while temp in numsSet:
                    temp += 1
                    length += 1
                maxLength = max(maxLength, length)

        return maxLength
