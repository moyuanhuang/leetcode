# 324. Wiggle Sort II
# medium

import random

class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        if not nums: return
        random.shuffle(nums)
        length = len(nums)
        self.sortKLargest(nums, 0, length - 1, (length - 1) // 2)
        # nums.sort(reverse=True)
        nums[:] = nums[::-1]
        # print(nums)
        median = nums[length // 2]

        vIndex = lambda x: (1 + 2 * x) % (length | 1)

        i, j, k = 0, 0, length - 1
        while j <= k:
            vj = vIndex(j)
            elem = nums[vj]
            if elem > median:
                vi = vIndex(i)
                nums[vi], nums[vj] = nums[vj], nums[vi]
                i += 1
                j += 1
            elif elem < median:
                vk = vIndex(k)
                nums[vj], nums[vk] = nums[vk], nums[vj]
                k -= 1
            elif elem == median:
                j += 1

    def sortKLargest(self, nums, lo, hi, k):
        if lo >= hi:
            return
        i, j = lo, hi
        while True:
            while i <= j and nums[i] <= nums[lo]: i += 1
            while j >= i and nums[j] >= nums[lo]: j -= 1
            if i > j:
                break
            nums[i], nums[j] = nums[j], nums[i]
        nums[lo], nums[j] = nums[j], nums[lo]
        
        if j == k:
            return
        elif j > k:
            self.sortKLargest(nums, lo, j - 1, k)
        else:
            self.sortKLargest(nums, j + 1, hi, k)
        return