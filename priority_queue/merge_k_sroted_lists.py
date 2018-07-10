# 23. Merge k Sorted Lists
# hard

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        from heapq import heappush, heappop, heapify, heapreplace

        dummy = ListNode(-1)
        pq = [(l.val, l) for l in lists if l]

        heapify(pq)
        
        head = dummy
        while pq:
            _, node = pq[0]
            if not node.next:
                heappop(pq)
            else:
                next_node = node.next
                heapreplace(pq, (next_node.val, next_node))
            head.next = node
            head = head.next
            
        return dummy.next
