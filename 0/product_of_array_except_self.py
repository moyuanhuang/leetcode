# 238. Product of Array Except Self
# medium

class Solution:
    def productExceptSelf(self, nums: 'List[int]') -> 'List[int]':
        right = 1
        zeroIndexes = set()
        for i, n in enumerate(nums):
            right *= n
            if n == 0:
                zeroIndexes.add(i)
        left = 1
        
        result = [0] * len(nums)
        for i in range(len(nums)):
            n = nums[i]
            if n == 0:
                zeroIndexes.remove(i)
                if len(zeroIndexes) == 0:
                    right = 1
                    for r in nums[i + 1:]:
                        right *= r
            else:
                right /= n
            result[i] = int(left * right)
            left *= n
            
        return result