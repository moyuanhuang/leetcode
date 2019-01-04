# 739. Daily Temperatures
# medium

class Solution:
    def dailyTemperatures(self, T):
        """
        :type T: List[int]
        :rtype: List[int]
        """
        prevTemp = []
        result = [0] * len(T)
        for i, temp in enumerate(T):
            while prevTemp and T[prevTemp[-1]] < temp:
                prevDay = prevTemp.pop()
                result[prevDay] = i - prevDay

            prevTemp.append(i)

        return result
