# 702. Search in a Sorted Array of Unknown Size
# medium

class Solution:
    def search(self, reader, target):
        """
        :type reader: ArrayReader
        :type target: int
        :rtype: int
        """
        lo, hi = 0, sys.maxsize
        while lo < hi:
            mid = lo + (hi - lo) // 2
            val = reader.get(mid)
            # print(mid, val)
            if val == 2147483647:
                hi = mid
            elif val > target:
                hi = mid
            elif val < target:
                lo = mid + 1
            else:
                return mid
        return -1