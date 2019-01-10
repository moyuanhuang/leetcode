# 658. Find K Closest Elements
# medium
    
class Solution:
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        if len(arr) < k:
            return arr
        right = bisect.bisect(arr, x)
        left = right - 1
        while k > 0:
            if right == len(arr):
                left -= 1
            elif left == -1:
                right += 1
            elif x - arr[left] <= arr[right] - x:
                left -= 1
            else:
                right += 1
            k -= 1
            
        return arr[left + 1: right]