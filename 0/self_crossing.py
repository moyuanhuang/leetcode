# 335. Self Crossing
# hard
# 当前线能不能被cross只用看之后的5条（+自己6条）就可以知道,
# 有两种cross的可能

class Solution:
    def isSelfCrossing(self, x):
        """
        :type x: List[int]
        :rtype: bool
        """
        size = len(x)
        x += [0] * 2

        for i in range(size - 3):
            up, left, down, right, up2, left2 = x[i : i + 6]
            print(up, left, down, right, up2, left2)
            if down <= up and right >= left:
                print(1)
                return True
            if down > up and right >= left and up2 >= down - up and up2 <= down and left2 >= right - left:
                print(2)
                return True

        return False

