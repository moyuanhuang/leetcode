# 752. Open the Lock
# medium

class Solution:
    def openLock(self, deadends_, target):
        """
        :type deadends: List[str]
        :type target: str
        :rtype: int
        """
        deadends = set(deadends_)
        if '0000' in deadends:
            return -1

        stack = ['0000']
        visited = set()

        step = 0
        while stack:
            size = len(stack)
            for _ in range(size):
                current = stack.pop(0)
                if current == target:
                    return step

                for i in range(4):
                    ch = current[i]
                    nextCh, prevCh = chr(ord(ch) + 1), chr(ord(ch) - 1)
                    if ch == '0':
                        prevCh = '9'
                    elif ch == '9':
                        nextCh = '0'

                    nextPswd = current[:i] + nextCh + current[i + 1:]
                    prevPswd = current[:i] + prevCh + current[i + 1:]
                    if nextPswd not in deadends and nextPswd not in visited:
                        stack.append(nextPswd)
                        visited.add(nextPswd)
                    if prevPswd not in deadends and prevPswd not in visited:
                        stack.append(prevPswd)
                        visited.add(prevPswd)
            step += 1
        return -1