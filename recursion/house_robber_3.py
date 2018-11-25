# 337. House Robber III
# medium
# key to the solution: what we do given a node?
# 1. rob: then we can only rob root.left.children, root.right.children
# 2. not rob: then we can rob root.left, root.right
# keep a map to avoid duplicated computation for the same node

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        my_map = {}

        def robsub(root):
            if not root: return 0
            if root in my_map: return my_map[root]

            val = 0
            if root.left:
                val += robsub(root.left.left) + robsub(root.left.right)
            if root.right:
                val += robsub(root.right.left) + robsub(root.right.right)
            res = max(root.val + val, robsub(root.left) + robsub(root.right))
            my_map[root] = res
            return res

        return robsub(root)

