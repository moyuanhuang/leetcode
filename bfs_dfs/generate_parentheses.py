# 22. Generate Parentheses
# medium

class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        result = []

        def helper(cur, left, right):
            if len(cur) == 2 * n:
                result.append(cur[:])
                return

            if left < n:
                helper(cur + '(', left + 1, right)

            if right < left:
                helper(cur + ')', left, right + 1)

            return

        helper('', 0, 0)
        return result
