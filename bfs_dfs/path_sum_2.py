# 113. Path Sum II
# medium

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        result = []

        def helper(node, path, target):
            if not node.left and not node.right and node.val == target:
                path.append(target)
                result.append(path[:])
                return

            if node.left:
                helper(node.left, path + [node.val], target - node.val)
            if node.right:
                helper(node.right, path + [node.val], target - node.val)
            return

        if not root:
            return []
        helper(root, [], sum)
        return result
