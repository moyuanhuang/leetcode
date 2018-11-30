# 281. Zigzag Iterator
# medium

class ZigzagIterator(object):

    def __init__(self, v1, v2):
        """
        Initialize your data structure here.
        :type v1: List[int]
        :type v2: List[int]
        """
        self.iters = [(0, iter(v1)), (1, iter(v2))]
        self.left = [len(v1), len(v2)]

    def next(self):
        """
        :rtype: int
        """
        index, iterator = -1, None
        while True:
            index, iterator = self.iters.pop(0)
            if self.left[index] != 0:
                break

        elem = next(iterator)
        self.iters.append((index, iterator))
        self.left[index] -= 1

        return elem

    def hasNext(self):
        """
        :rtype: bool
        """
        return sum(self.left) != 0
        

# Your ZigzagIterator object will be instantiated and called as such:
# i, v = ZigzagIterator(v1, v2), []
# while i.hasNext(): v.append(i.next())
