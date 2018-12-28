# 776. Split BST
# medium

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def splitBST(self, root, V):
        """
        :type root: TreeNode
        :type V: int
        :rtype: List[TreeNode]
        """
        if not root:
            return [None, None]

        if root.val > V:
            subLeft, subRigh = self.splitBST(root.left, V)
            root.left = subRigh
            return [subLeft, root]
        else:
            subLeft, subRigh = self.splitBST(root.right, V)
            root.right = subLeft
            return [root, subRigh]
