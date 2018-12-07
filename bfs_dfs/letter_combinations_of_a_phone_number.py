# 17. Letter Combinations of a Phone Number
# medium

class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        def helper(i, cur):
            if i == len(digits):
                result.append(cur[:])
                return

            num = digits[i]
            for ch in keyMapping[num]:
                helper(i + 1, cur + ch)

            return 

        keyMapping = {
            '2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n','o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z']
        }

        result = []
        if not digits:
            return result

        helper(0, '')

        return result
