# 251. Flatten 2D Vector
# medium

class Vector2D(object):

    def __init__(self, vec2d):
        """
        Initialize your data structure here.
        :type vec2d: List[List[int]]
        """
        self.vectors = vec2d
        self.row = 0
        self.index = 0

    def next(self):
        """
        :rtype: int
        """
        if self.index >= len(self.vectors[self.row]):
            self.row = self.getNextNonEmptyRow()
            self.index = 0
        ret = self.vectors[self.row][self.index]
        self.index += 1
        return ret

    def hasNext(self):
        """
        :rtype: bool
        """
        if len(self.vectors) == 0:
            return False

        if self.index < len(self.vectors[self.row]):
            return True
        row = self.getNextNonEmptyRow()
        if row > 0:
            return True
        return False
    
    def getNextNonEmptyRow(self):
        temp = self.row + 1
        while temp < len(self.vectors):
            if len(self.vectors[temp]) != 0:
                return temp
            temp += 1
        return -1

# Your Vector2D object will be instantiated and called as such:
# i, v = Vector2D(vec2d), []
# while i.hasNext(): v.append(i.next())