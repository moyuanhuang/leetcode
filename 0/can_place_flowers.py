# 605. Can Place Flowers
# medium

class Solution:
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        length = len(flowerbed)
        if n == 0:
            return True
        if length == 0 or n > math.ceil(length / 2):
            return False
        if length == 1:
            return flowerbed[0] == 0
        for i in range(length):
            if (flowerbed[i]):
                continue
            if (i > 0 and flowerbed[i-1]):
                continue
            if (i < length - 1 and flowerbed[i+1]):
                continue
            flowerbed[i] = 1
            n -= 1
            if n == 0:
                return True
        return False

