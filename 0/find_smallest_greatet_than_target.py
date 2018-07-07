# 744. Find Smallest Letter Greater Than Target
# easy

class Solution:
    def nextGreatestLetter(self, letters, target):
        """
        :type letters: List[str]
        :type target: str
        :rtype: str
        """
        if not letters: return ""
        
        lo, hi = 0, len(letters) - 1

        while lo < hi:
            mid = lo + (hi - lo) // 2
            if letters[mid] <= target:
                lo = mid + 1
            else:
                hi = mid
        if letters[lo] > target:
            return letters[lo]
        else:
            return letters[0]
