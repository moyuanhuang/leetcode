# 438. Find All Anagrams in a String
# easy

from collections import defaultdict
class Solution:
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        target = defaultdict(int)
        for ch in p:
            target[ch] += 1
        words = defaultdict(int)

        def isValid():
            for ch, count in target.items():
                if words[ch] != count:
                    return False
            return True

        result = []
        left, right = 0, 0
        while right < len(s):
            currentLength = right - left + 1
            if currentLength < len(p):
                right += 1
                words[ch[right]] += 1
            elif currentLength > len(p):
                words[s[left]] -= 1
                left += 1
            elif currentLength == len(p):
                if isValid():
                    result.append(left)

                right += 1
                words[ch[right]] += 1

        return result
