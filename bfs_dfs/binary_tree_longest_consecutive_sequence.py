# 298. Binary Tree Longest Consecutive Sequence
# medium

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def longestConsecutive(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.maxLength = 0

        def helper(node, prev, currentLength):
            if not node:
                self.maxLength = max(self.maxLength, currentLength - 1)
                return
            
            if prev + 1 != node.val:
                self.maxLength = max(self.maxLength, currentLength - 1)
                currentLength = 1

            helper(node.left, node.val, currentLength + 1)
            helper(node.right, node.val, currentLength + 1)

        if not root:
            return 0
        helper(root, root.val, 0)
        return self.maxLength
