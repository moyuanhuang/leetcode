
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        self.result = []
        self.helper(root)
        return self.result

    def helper(self, root):
        if not root:
            return -1

        left_dep, right_dep = 0, 0
        left_dep = self.helper(root.left)
        right_dep = self.helper(root.right)
        depth = max(right_dep, left_dep) + 1

        if len(self.result) == depth:
            self.result.append([root.val])
        else:
            self.result[depth].append(root.val)
        return depth
