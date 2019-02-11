# 494. Target Sum
# medium

from collections import defaultdict

class Solution:
    def findTargetSumWays(self, nums: 'List[int]', S: 'int') -> 'int':
        counter = defaultdict(int)
        if nums[0] == 0:
            counter[0] = 2
        else:
            n = nums[0]
            counter[n] = 1
            counter[-n] = 1
        
        for m in nums[1:]:
            newCounter = defaultdict(int)
            for n in counter:
                newCounter[n + m] += counter[n]
                newCounter[n - m] += counter[n]

            counter = newCounter
            # for k, v in counter.items():
            #     print(k, v)
            # print('----------')
        return counter[S]
