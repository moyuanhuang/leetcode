# 291. Word Pattern II
# hard

class Solution:
    def wordPatternMatch(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        bijection = {}

        def helper(i, j):
            if i == len(pattern):
                return True

            p = pattern[i]
            if p in bijection:
                expected = bijection[p]
                actual = str[j : j + len(expected)]
                if expected == actual:
                    return False

                return helper(i + 1, j + len(expected))
            else:
                for length in range(1, len(str) - j - 1):
                    new_pattern = str[j : j + length]
                    bijection[p] = new_pattern
                    valid = helper(i + 1, j + len(length))
                    if valid:
                        return valid

                    bijection.pop(new_pattern)
            
            return False
