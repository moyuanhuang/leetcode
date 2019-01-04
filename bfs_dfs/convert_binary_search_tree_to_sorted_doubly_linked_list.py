# 426. Convert Binary Search Tree to Sorted Doubly Linked List
# medium

"""
# Definition for a Node.
class Node:
    def __init__(self, val, left, right):
        self.val = val
        self.left = left
        self.right = right
"""
class Solution:
    def treeToDoublyList(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        if not root:
            return None

        stack = []
        temp = root
        while temp:
            stack.append(temp)
            temp = temp.left

        entry = Node(-1, None, None)
        prev = entry

        while stack:
            node = stack.pop()

            prev.right = node
            node.left = prev
            temp = node.right
            while temp:
                stack.append(temp)
                temp = temp.left

            prev = node

        first = entry.right
        prev.right = first
        first.left = prev

        return first