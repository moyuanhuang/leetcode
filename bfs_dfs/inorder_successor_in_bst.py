# 285. Inorder Successor in BST
# medium

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    # classic recusion that I will never understand
    def inorderSuccessor(self, root, p):
        """
        :type root: TreeNode
        :type p: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return None
        if root.val > p.val:
            return self.inorderSuccessor(root.left, p) or root
        return self.inorderSuccessor(root.right, p)


    # just plain bfs
    def inorderSuccessor_(self, root, p):
        """
        :type root: TreeNode
        :type p: TreeNode
        :rtype: TreeNode
        """

        # push succesor
        def push_next(node):
            it = node.right
            while it:
                ancestors.append(it)
                it = it.left

        ancestors = []
        # pre-processing root node so that it can be processed by push_next()
        dummy = TreeNode(-1)
        dummy.right = root
        push_next(dummy)

        while len(ancestors):
            node = ancestors.pop()

            push_next(node)
            if node.val == p.val:
                break

        if len(ancestors):
            return ancestors.pop()
        else:
            return None
