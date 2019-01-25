# 862. Shortest Subarray with Sum at Least K
# hard

class Solution:
    def shortestSubarray(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        N = len(A)
        B = A[:]
        for i in range(1, N):
            B[i] += B[i - 1]

        B.insert(0, 0)
        res = N + 1
        queue = collections.deque()
        for i in range(N + 1):
            while queue and B[i] - B[queue[0]] >= K:
                res = min(res, i - queue.popleft())
            while queue and B[i] <= B[queue[-1]]:
                queue.pop()
            queue.append(i)
        return res if res <= N else -1

