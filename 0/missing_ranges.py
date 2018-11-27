# 163. Missing Ranges
# medium

class Solution:
    def findMissingRanges(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: List[str]
        """

        def get_range(left, right):
            start = left + 1
            end = right - 1
            if start == end:
                return str(start)
            else:
                return str("%d->%d" % (start, end))

        # corner case
        # 1. nums is empty
        if len(nums) == 0:
            nums = [lower - 1, upper + 1]

        # pre-processing
        if nums[0] != lower:
            nums.insert(0, lower - 1)
        if nums[-1] != upper:
            nums.append(upper + 1)

        result = []


        for i in range(len(nums) - 1):
            left, right = nums[i], nums[i + 1]
            if left == right:
                continue
            if left != right - 1:
                result.append(get_range(left, right))

        return result
