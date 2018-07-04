# 671. Second Minimum Node In a Binary Tree
# easy

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findSecondMinimumValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return -1

        self.minimum = root.val
        self.second_min = sys.maxsize
        
        def helper(node):
            if not node:
                return
            if node.val > self.minimum and node.val < self.second_min:
                self.second_min = node.val
            if node.left:
                helper(node.left)
                helper(node.right)

        helper(root)
        
        if self.second_min == sys.maxsize:
            return -1
        else:
            return self.second_min

