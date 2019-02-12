# 287. Find the Duplicate Number
# medium

class Solution:
    def findDuplicate(self, nums: 'List[int]') -> 'int':
        i = 0
        while i < len(nums):
            if nums[i] == i + 1:
                i += 1
                continue
            while nums[i] != i + 1:
                a = nums[i]
                b = nums[a - 1]
                if a == b:
                    return a
                nums[i], nums[a - 1] = b, a
            i += 1
        return -1
