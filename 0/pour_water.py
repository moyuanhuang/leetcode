# 755. Pour Water
# medium

class Solution:
    def pourWater(self, heights, V, K):
        """
        :type heights: List[int]
        :type V: int
        :type K: int
        :rtype: List[int]
        """
        while V > 0:
            index = K
            for i in range(K - 1, -1, -1):
                if heights[i] > heights[i + 1]:
                    break
                if heights[i] < heights[i + 1]:
                    index = i
            if index != K:
                heights[index] += 1
                V -= 1
                continue

            for i in range(K + 1, len(heights)):
                if heights[i] > heights[i - 1]:
                    break
                if heights[i] < heights[i - 1]:
                    index = i
            heights[index] += 1
            V -= 1

        return heights
            