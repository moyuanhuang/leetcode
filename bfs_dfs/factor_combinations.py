class Solution:
    def getFactors(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        return self.helper(2, n)

    def helper(self, start, n):
        ret = []
        for i in range(start, n):
            if i * i > n:
                break
            if n % i == 0:
                ret.append([i, n // i])
                sub_factors = self.helper(i, n // i)
                for factors in sub_factors:
                    ret.append([i] + factors)
        return ret


# if __name__ == "__main__":
#     sol = Solution()
#     res = sol.getFactors(24)
#     for r in res:
#         print(r)
