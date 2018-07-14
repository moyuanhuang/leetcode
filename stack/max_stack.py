# 716. Max Stack
# hard
# Take Away: heap sort is not stable, doesn't preserve order of the same key

import heapq

class DLinkedList(object):
    def __init__(self, val):
        self.val = val
        self.next = None
        self.prev = None
        return

class MaxStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = None  # stack
        self.heap = []
        heapq.heapify(self.heap)

        self.first_to_pop = {}  # order of the elem with same key
        return
        
    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        temp = DLinkedList(x)
        if not self.stack:
            self.stack = temp
        else:
            self.stack.next = temp
            temp.prev = self.stack
            self.stack = temp
        
        heapq.heappush(self.heap, -x)

        order = self.first_to_pop.get(x, [])
        order.append(temp)
        self.first_to_pop[x] = order
        return

    def pop(self):
        """
        :rtype: int
        """
        ret = self.stack
        self.stack = self.stack.prev
        self.first_to_pop[ret.val].pop(-1)
        return ret     

    def top(self):
        """
        :rtype: int
        """
        return self.stack.val
        

    def peekMax(self):
        """
        :rtype: int
        """
        return -self.heap[0]
        

    def popMax(self):
        """
        :rtype: int
        """
        while True:
            x = -heapq.heappop(self.heap)
            if not self.first_to_pop[x] is None:
                break
        node = self.first_to_pop[x].pop(-1)
        prev = node.prev
        nxt = node.next
        if prev:
            prev.next = nxt
        if nxt:
            nxt.prev = prev
        else:
            self.stack = prev
        return x

# Your MaxStack object will be instantiated and called as such:
# obj = MaxStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.peekMax()
# param_5 = obj.popMax()

if __name__ == '__main__':
    st = MaxStack()
    st.push(5)
    st.push(1)
    st.push(5)
    st.push(3)
    print(st.top(), st.peekMax())
    print(st.popMax())
    print(st.top(), st.peekMax())
    print(st.popMax())
    print(st.top(), st.peekMax())
