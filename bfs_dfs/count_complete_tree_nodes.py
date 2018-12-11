# 222. Count Complete Tree Nodes
# medium

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # recursion with O((logn) ^ 2)
    # iterative version
    def height(self, node):
        it = node
        h = -1
        while it:
            it = it.left
            h += 1

        return  h

    def countNodes1(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        count = 0
        it = root
        while it:
            h = self.height(it)
            right_h = self.height(it.right)
            if right_h == h - 1:
                count += 2 ** h
                it = it.right
            else:
                count += 2 ** (h -1)
                it = it.left

        return count

    # recursive version
    def countNodes2(self, root):
        if not root:
            return 0

        h = self.height(root)
        right_h = self.height(root.right)

        if right_h == h - 1:
            return 2 ** h + self.countNodes2(root.right)
        else:
            return 2 ** (h - 1) + self.countNodes2(root.left)


    # dumb BFS solution, O(2^h) time complexity
    def countNodes_(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.maxH = 0
        self.leaveCount = 0
        self.foundLastNode = False

        def helper(node, height):
            if self.foundLastNode :
                return 0

            if not node:
                self.maxH = max(self.maxH, height - 1)
                return 0

            left = helper(node.left, height + 1)
            right = helper(node.right, height + 1)

            if height == self.maxH:
                self.leaveCount += 1
                return 1

            if height == self.maxH - 1 and (left + right < 2):
                self.foundLastNode = True
                return 0
                
            return 0

        helper(root, 0)
        return 2 ** (self.maxH) - 1 + self.leaveCount
