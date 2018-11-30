# 384. Shuffle an Array
# medium

from random import shuffle

class Solution:

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.origin = nums
        

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        return self.origin
        

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        indexes = [i for i in range(len(self.origin))]
        shuffle(indexes)

        shuffled_arr = []
        for i in indexes:
            shuffled_arr.append(self.origin[i])

        return shuffled_arr
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
