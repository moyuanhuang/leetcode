# 543. Diameter of Binary Tree
# easy

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.best = 1
        self.depth(root)
        return self.best - 1

    def depth(self, root):
        if not root:
            return 0

        ldep = self.depth(root.left)
        rdep = self.depth(root.right)
        self.best = max(self.best, ldep + rdep + 1)
        return max(ldep, rdep) + 1

