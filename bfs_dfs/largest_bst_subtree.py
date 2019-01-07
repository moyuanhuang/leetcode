# 333. Largest BST Subtree
# medium

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import sys

class Solution:
    class Result:
        def __init__(self, size, lower, upper):
            self.size = size
            self.lower = lower
            self.upper = upper
            
    def largestBSTSubtree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.maxSize = 0
        # return (size, lower, upper)
        def helper(root):
            if not root:
                return self.Result(0, sys.maxsize, -sys.maxsize - 1)

            left = helper(root.left)
            right = helper(root.right)
            if left.size == -1 or right.size == -1 or \
             left.upper >= root.val or right.lower <= root.val:
                return self.Result(-1, 0, 0)

            size = left.size + 1 + right.size
            self.maxSize = max(self.maxSize, size)
            return self.Result(size, min(left.lower, root.val), max(right.upper, root.val))

        helper(root)
        return self.maxSize
