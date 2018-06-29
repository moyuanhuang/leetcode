# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
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

class Solution:
    def depthSumInverse(self, nestedList):
        """
        :type nestedList: List[NestedInteger]
        :rtype: int
        """
        input = new NestedInteger(nestedList)
        max_depth = get_max_depth(input, 1)
        print("max depth is", max_depth)

        helper(input, 0)
        return self.sum

    def get_max_depth(cur, depth)
        if cur.isInteger()
            return depth

        li = cur.getList()
        ret = 0
        for l in li:
            ret = max(ret, get_max_depth(l, depth + 1)
        return ret
        
    
    def helper(nestedInteger, depth)
        if nestedInteger.isInteger()
            self.sum += (self.max_depth - depth + 1) * nestedInteger.getInteger()
            return

        for li in nestedInteger:
            helper(li, depth + 1)

        return
