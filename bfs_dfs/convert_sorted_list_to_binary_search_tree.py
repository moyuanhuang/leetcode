# 109. Convert Sorted List to Binary Search Tree
# medium

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        if not head:
            return None
        # single node
        if not head.next:
            return head

        slow, fast = head, head

        prev = None
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next

        prev.next = None # cut the linked list: ... --> prev -/-> slow --> ...

        newNode = TreeNode(slow.val)
        newNode.left = self.sortedListToBST(head)
        newNode.right = self.sortedListToBST(slow.next)

        return newNode
