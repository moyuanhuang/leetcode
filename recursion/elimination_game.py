# 390. Elimination Game
# medium

class Solution(object):
    def lastRemaining(self, n):
        """
        :type n: int
        :rtype: int
        """
        self.dir = {'->': '<-', '<-': '->'}
        direction = '->'
        res = 0
        if n % 2 == 0:
            res = self.find_even(n, direction)
        else:
            res = self.find_odd(n, direction)
        return res 

    def find_even(self, n, direction):
        if n == 2:
            if direction == '->':
                return 2
            else:
                return 1
        next_n = n // 2
        if next_n % 2 == 0:
            res = 2 * self.find_even(next_n, self.dir[direction])
        else:
            res = 2 * self.find_odd(next_n, self.dir[direction])
        if direction == '<-':
            res -= 1
        return res 

    def find_odd(self, n, direction):
        if n == 1 or n == 3:
            return (n + 1) // 2
        next_n = n // 2
        if next_n % 2 == 0:
            res = 2 * self.find_even(next_n, self.dir[direction])
        else:
            res = 2 * self.find_odd(next_n, self.dir[direction])
        return res

