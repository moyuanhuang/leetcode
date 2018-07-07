# 698. Partition to K Equal Sum Subsets
# medium

# class Solution:
#     def canPartitionKSubsets(self, nums, k):
#         """
#         :type nums: List[int]
#         :type k: int
#         :rtype: bool
#         """
#         def put(nums, buckets):
#             if len(nums) == 0:
#                 for b in buckets:
#                     if b != self.subset_sum:
#                         return False
#                 return True

#             n = nums.pop(0)
#             for i, b in enumerate(buckets):
#                 if b + n > self.subset_sum:
#                     continue
#                 buckets[i] = b + n
#                 if put(nums[:], buckets):
#                     return True
#                 buckets[i] = b
                
#                 # why we need this??
#                 if buckets[i] == 0:
#                     return False
#             return False

#         buckets = [0] * k
#         # why we need to sort??
#         nums.sort(reverse=True)
#         self.subset_sum = sum(nums) / k
#         return put(nums, buckets)

class Solution:
    def canPartitionKSubsets(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """

        def solve(nums, target, k, is_used, cur_sum, start):
            if not k:
                if sum(is_used) == len(nums):
                    return True
                else:
                    return False
            for i, n in enumerate(nums[start:]):
                if is_used[start + i]:
                    continue
                is_used[start + i] = 1
                if cur_sum + n < target:
                    if solve(nums, target, k, is_used, cur_sum + n, start + i + 1):
                        return True
                elif cur_sum + n == target:
                    if solve(nums, target, k - 1, is_used, 0, 0):
                        return True
                is_used[start + i] = 0
            return False

        subset_sum = sum(nums) // k 
        is_used = [0] * len(nums)
        return solve(nums, subset_sum, k, is_used, 0, 0)


# if __name__ == '__main__':
#     sol = Solution()
#     arr = [3522,181,521,515,304,123,2512,312,922,407,146,1932,4037,2646,3871,269] 
#     k = 5
#     print(sum(arr) / 5)
#     res = sol.canPartitionKSubsets(arr, k)
#     print(res)

