# 341. Flatten Nested List Iterator
# medium

# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger(object):
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class NestedIterator(object):

    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        self.stack = nestedList[::-1]
        self.prepare_next_integer()

    def next(self):
        """
        :rtype: int
        """
        ret = self.stack.pop().getInteger()
        self.prepare_next_integer()
        return ret

    def hasNext(self):
        """
        :rtype: bool
        """
        return len(self.stack) != 0

    def prepare_next_integer(self):
        while self.stack:
            item = self.stack[-1]
            if item.isInteger():
                break
            else:
                item = self.stack.pop()
                nestedList = item.getList()
                for i in range(len(nestedList) - 1, -1, -1):
                    temp = nestedList[i]
                    if not temp.isInteger() and len(temp.getList()) == 0:
                        continue
                    else:
                        self.stack.append(nestedList[i])

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []

# while i.hasNext(): v.append(i.next())