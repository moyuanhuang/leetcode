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
            return root

        nodes = [root]
        while nodes:
            nextLevelNodes = []
            while nodes:
                node = nodes.pop(0)
                if len(nodes):
                    node.next = nodes[0]
                else:
                    node.next = None
                if node.left: nextLevelNodes.append(node.left)
                if node.right: nextLevelNodes.append(node.right)
            nodes = nextLevelNodes
        return
