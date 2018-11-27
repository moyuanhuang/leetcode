# 159. Longest Substring with At Most Two Distinct Characters
# hard

from collections import defaultdict

class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s):
        """
        :type s: str
        :rtype: int
        """
        i = 0
        lengths = [0] * (len(s) + 1)
        char_set = set()

        consecutive = 0
        while i < len(s):
            cur = s[i]
            if cur in char_set:
                lengths[i] = lengths[i - 1] + 1
            elif len(char_set) < 2:
                char_set.add(cur)
                lengths[i] = lengths[i -1] + 1
            else:
                char_set = set([cur, cur[i - 1]])
                lengths[i] = consecutive + 1

            if i > 0 and cur == s[i - 1]:
                consecutive += 1
            else:
                consecutive = 1

            i += 1

        return max(lengths)
