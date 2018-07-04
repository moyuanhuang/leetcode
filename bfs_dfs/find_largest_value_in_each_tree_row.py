# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []

        stack = []
        stack.append(root)
        result = []

        while stack:
            next_st = []
            largest = -sys.maxsize - 1
            while stack:
                node = stack.pop(0)
                largest = max(largest, node.val)
                if node.left:
                    next_st.append(node.left)
                if node.right:
                    next_st.append(node.right)
            result.append(largest)
            stack = next_st

        return result
