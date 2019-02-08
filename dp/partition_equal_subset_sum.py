# 416. Partition Equal Subset Sum
# medium

class Solution:
    def canPartition(self, nums: 'List[int]') -> 'bool':
        if sum(nums) % 2 != 0: return False
        
        target = sum(nums) // 2
        dp = [[False] * (target + 1) for i in range(len(nums) + 1)]
        dp[0][0] = True
            
        for i in range(1, len(nums) + 1):
            dp[i][0] = True
            n = nums[i - 1]

            for s in range(n, target + 1):
                dp[i][s] = dp[i - 1][s] or dp[i - 1][s - n]

            if dp[i][target]:
                return True

        return False
