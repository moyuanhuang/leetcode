# 215. Kth Largest Element in an Array
# medium

# nums[lo]: pivot
# i scans from left to right to find the first lager number
# j scans from right to left to find the first small number
# swap nums[i] and nums[j]
# swau nums[lo] with NUMS[J] !!!

import random

class Solution:
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # shuffle the array so we are guaranteed to have O(N) time complexity
        random.shuffle(nums)

        length = len(nums)
        indexToFind = length - k
        lo, hi = 0, length - 1

        while lo < hi:
            i, j = lo, hi
            while True:
                # the bound SHOULD NOT BE i <= j, we need to make nums[j] always smaller
                # than nums[lo] so we can sway them
                while i < length and nums[i] <= nums[lo]: i += 1
                while j > 0 and nums[j] >= nums[lo]: j -= 1
                if i >= j:
                    break
                nums[i], nums[j] = nums[j], nums[i]

            nums[lo], nums[j] = nums[j], nums[lo]

            if indexToFind > j:
                lo = j + 1
            elif indexToFind < j:
                hi = j - 1
            else:
                return nums[j]

        return nums[lo]
