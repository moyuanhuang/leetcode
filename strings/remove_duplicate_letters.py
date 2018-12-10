# 316. Remove Duplicate Letters
# hard


class Solution:
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        lastOccOfChar = {}
        for i, v in enumerate(s):
            lastOccOfChar[v] = i

        # splice the array
        ends = []
        for _, v in lastOccOfChar.items():
            ends.append(v)
        ends.sort()

        result = ""
        start = 0
        usedChar = set()

        while ends:
            nextStart = None
            end = ends[0]
            smallest = chr(ord('z') + 1)
            smallestIndex = None

            # find a smallest CHar in [start, end]
            for i in range(start, end + 1):
                ch = s[i]
                if ch in usedChar:
                    continue
                if ch < smallest:
                    smallest = ch
                    smallestIndex = i
                    nextStart = i + 1

            # append the smallest char
            result += smallest
            usedChar.add(smallest)

            # remove the lastOcc of the smallest element
            lastOccIndex = lastOccOfChar[smallest]
            ends.remove(lastOccIndex)

            start = nextStart

        return result
