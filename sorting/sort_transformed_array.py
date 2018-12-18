# 360. Sort Transformed Array
# medium

# let's assum by 'sorted' we mean from smaller to bigger

from heapq import heappop, heappush

class Solution:
    def sortTransformedArray(self, nums, a, b, c):
        """
        :type nums: List[int]
        :type a: int
        :type b: int
        :type c: int
        :rtype: List[int]
        """

        def f(x):
            return a * (x ** 2) + b * x + c

        nums[:] = [f(x) for x in nums]
        if a == 0:
            if b > 0:
                return nums
            else:
                return nums[::-1]

        result = [0] * len(nums)
        left, right = 0, len(nums) - 1

        index = left if a < 0 else right
        while left <= right:
            if a < 0:
                if nums[left] > nums[right]:
                    result[index] = nums[right]
                    right -= 1
                else:
                    result[index] = nums[left]
                    left += 1
                index += 1
            else:
                if nums[left] > nums[right]:
                    result[index] = nums[left]
                    left += 1
                else:
                    result[index] = nums[right]
                    right -= 1
                index -= 1

        return result
