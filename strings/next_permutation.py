# 31. Next Permutation
# medium

class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        i, j = len(nums) - 2, len(nums) - 1
        while i >= 0:
            if nums[i] < nums[i + 1]:
                break
            i -= 1

        # corner case: [5, 4, 3, 2, 1]
        if i < 0:
            nums[:] = nums[::-1]
            return

        # find the first element that is larger than nums[i]
        # watch for the equal sign here, this account for the
        # corner case [1, 5, 1] -> [5, 1, 1]
        while nums[j] <= nums[i]:
            j -= 1

        # swap
        nums[i], nums[j] = nums[j], nums[i]

        # reverse
        nums[i + 1:] = nums[i + 1:][::-1]
        
        return
