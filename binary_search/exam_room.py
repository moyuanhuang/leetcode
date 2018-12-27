# 855. Exam Room
# medium

class ExamRoom(object):

    def __init__(self, N):
        """
        :type N: int
        """
        self.seatedIndexes = []
        self.N = N

    def seat(self):
        """
        :rtype: int
        """
        if len(self.seatedIndexes) == 0:
            self.seatedIndexes.append(0)
            return 0

        maxDistance, seat = self.seatedIndexes[0], 0
        for i in range(len(self.seatedIndexes) - 1):
            left, right = self.seatedIndexes[i], self.seatedIndexes[i + 1]
            temp = (right - left) // 2

            if temp > maxDistance:
                maxDistance = temp
                seat = (left + right) // 2
        if self.N - 1 - self.seatedIndexes[-1] > maxDistance:
            seat = self.N - 1
        bisect.insort(self.seatedIndexes, seat)
        return seat

    def leave(self, p):
        """
        :type p: int
        :rtype: void
        """
        self.seatedIndexes.remove(p)

# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(N)
# param_1 = obj.seat()
# obj.leave(p)