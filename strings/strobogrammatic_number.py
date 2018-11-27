# 246. Strobogrammatic Number
# easy

class Solution:
    def isStrobogrammatic(self, num):
        """
        :type num: str
        :rtype: bool
        """
        mapping = {
            '0': '0',
            '1': '1',
            '6': '9',
            '8': '8',
            '9': '6',
        }
        reverse = ""
        for ch in num[::-1]:
            if ch not in mapping:
                return False
            reverse += mapping[ch]

        return reverse == num
