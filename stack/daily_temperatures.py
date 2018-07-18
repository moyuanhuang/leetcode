# 739. Daily Temperatures
# medium

class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        stack = []
        length = len(temperatures)
        res = [0] * length
        for i in range(length):
            while stack and temperatures[i] > temperatures[stack[-1]]:
                ind = stack.pop(-1)
                res[ind] = i - ind
            stack.append(i)
        return res
