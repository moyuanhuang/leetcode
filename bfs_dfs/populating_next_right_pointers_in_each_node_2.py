# 117. Populating Next Right Pointers in Each Node II
# medium

# Definition for binary tree with next pointer.
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        if not root:
            return
        stack = [root]
        while stack:
            nextLevel = []
            while stack:
                node = stack.pop(0)
                nextNode = None
                if len(stack) != 0:
                    nextNode = stack[0]
                node.next = nextNode

                if node.left:
                    nextLevel.append(node.left)
                if node.right:
                    nextLevel.append(node.right)
            stack = nextLevel

        return
