# 300. Longest Increasing Subsequence
# medium

from collections import defaultdict

class Solution:
    def lengthOfLIS(self, nums: 'List[int]') -> 'int':
        if not nums: return 0

        sequences = defaultdict(int)
        for n in nums:
            maxLength = 1
            for start, length in sequences.items():
                if n > start:
                    maxLength = max(maxLength, length + 1)

            sequences[n] = maxLength

        return max(sequences.values())
