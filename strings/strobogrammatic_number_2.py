# 247. Strobogrammatic Number II
# medium

class Solution:
    def findStrobogrammatic(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        self_symetric = {
            '0': '0',
            '1': '1',
            '8': '8'
        }

        factory = {
            '0': '0',
            '1': '1',
            '8': '8',
            '6': '9',
            '9': '6'
        }

        pivot = n // 2
        result = []

        def helper(i, cur):
            # leaf node
            if i == pivot:
                if n % 2 == 1:
                    # When n is odd, need to fill the pivot, e.g. [8, 6, -, 6, 8]
                    for x in self_symetric:
                        cur[i] = x
                        result.append(cur)
                else:
                    # When n is even, no special operation needed
                    result.append(cur)
                return
                    
            for x in factory:
                # '0' can't be placed in the begining
                if i == 0 and x == '0':
                    continue
                cur[i] = x
                cur[n - i - 1] = factory[x]
                helper(i + 1, cur[:])
        
        helper(0, '-' * n)
        return result
