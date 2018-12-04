# 235. Lowest Common Ancestor of a Binary Search Tree
# easy

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if root.val > p.val and root.val > q.val:
            return self.lowestCommonAncestor(root.left, p, q)
        elif root.val < p.val and root.val < q.val:
            return self.lowestCommonAncestor(root.right, p, q)
        else:
            return root


    # dumb solution
    def lowestCommonAncestor_(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        self.result = None

        def helper(node):
            if not node:
                return (False, False)

            left_p, left_q = self.lowestCommonAncestor(node.left, p, q)
            right_p, right_q = self.lowestCommonAncestor(node.right, p, q)

            contains_p = left_p or right_p or node.val == p.val
            contains_q = left_q or right_q or node.val == q.val
                
            if contains_p and contains_q:
                if not self.result:
                    self.result = node

            return (contains_p, contains_q)

        helper(root)
        return self.result
