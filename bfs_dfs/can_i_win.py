# 464. Can I Win
# medium
# a faster solution is to use bitmap

class Solution:
    def canIWin(self, maxChoosableInteger, desiredTotal):
        """
        :type maxChoosableInteger: int
        :type desiredTotal: int
        :rtype: bool
        """
        self.hash = {}
        return self.helper(range(maxChoosableInteger, desiredTotal)

    def helper(self, nums, desiredTotal):
        seq = str(nums)
        if seq in self.hash:
            return self.hash[seq]

        if nums[-1] >= desiredTotal:
            return True

        max_to_win = desiredTotal - nums[-1] - 1
        for i in nums:
            if nums[i] >= max_to_win:
                return False
            if not self.helper(nums[:i] + nums[i+1:], desiredTotal - nums[i]):
                return True
            self.hash[str(nums)] = False
        return False
