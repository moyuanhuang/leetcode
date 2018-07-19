# 413. Arithmetic Slices
# medium

class Solution:
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        self.res = 0
        if len(A) < 3: return self.res

        start, end = 0, 0
        prev, cur, nxt = 0, 1, 2
        while True:
            if nxt >= len(A):
                self.find_seq(start, end)
                break

            if A[cur] - A[prev] == A[nxt] - A[cur]:
                end = nxt
            else:
                self.find_seq(start, end)
                start = cur
            prev += 1
            cur += 1
            nxt += 1
        return self.res
            
    def find_seq(self, start, end):
        length = end - start + 1
        if length < 3:
            return 0
        for n in range(3, length + 1):
            self.res += length - n + 1
