class Solution:
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        kind = {}
        candy = 0
        for c in candies:
            if candy == len(candies) / 2:
                return len(kind.keys())
            if not c in kind:
                kind[c] = 1
                candy += 1
        return len(kind.keys())
