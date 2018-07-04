class Solution:
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if not num:
            return True

        n_digits = 0
        temp = num
        while temp:
            n_digits += 1
            temp //= 10

        lo, hi = 1, max(4, 10 ** (n_digits - 1) - 1)
        while lo < hi:
            mid = lo + (hi - lo) // 2
            if mid ** 2 < num:
                lo = mid + 1
            elif mid ** 2 > num:
                hi = mid
            else:
                return True
        return False

# if __name__ == '__main__':
#     sol = Solution()
#     num = input('input a number\n')
#     valid = sol.isPerfectSquare(int(num))
#     print(valid)
