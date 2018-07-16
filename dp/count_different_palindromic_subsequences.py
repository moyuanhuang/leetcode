# 730. Count Different Palindromic Subsequences
# hard
# dp[len][i][x], the distinct subsequences with length len, starting from i, with start char as x
# if s[i] != x:
#   dp[len][i][x] = dp[len-1][i+1][x]
# elif s[i + len - 1] != x:
#   dp[len][i][x] = dp[len-1][i][x]
# else:
#   dp[len][i][x] = dp[len - 2][i-1][x^]

import numpy as np

class Solution(object):
    def countPalindromicSubsequences(self, S):
        """
        :type S: str
        :rtype: int
        """
        ALPH = ['a', 'b', 'c', 'd']
        mod = 10**9 + 7
        
        length = len(S)
        dp = np.zeros([length + 1, length, 4], dtype='int')

        for l in range(1, length + 1):
            for i in range(length):
                j = i + l - 1
                if j >= length:
                    break
                for k, x in enumerate(ALPH):
                    if l == 1:
                        dp[l][i][k] = S[i] == x
                    elif S[i] != x:
                        dp[l][i][k] = dp[l-1][i+1][k]
                    elif S[j] != x:
                        dp[l][i][k] = dp[l-1][i][k]
                    else:
                        cnt = 2
                        for m, y in enumerate(ALPH):
                            cnt += dp[l - 2][i + 1][m]
                        dp[l][i][k] = cnt % mod

        return int(sum(dp[length][0]) % mod)

