# 773. Sliding Puzzle
# hard

class Solution(object):
    def slidingPuzzle(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        options = [
            [1, 3],
            [0, 2, 4],
            [1, 5],
            [0, 4],
            [1, 3, 5],
            [2, 4]
        ]
        targetStr = '123450'

        start = ''.join(str(x) for x in (board[0] + board[1]))
        stack = [start]
        visited = set(stack)
        steps = 0
        while stack:
            nextStack = []
            # print(stack)
            while stack:
                state = stack.pop(0)
                if state == targetStr:
                    return steps
                slist = list(state)
                i = slist.index('0')
                
                for endPosition in options[i]:
                    slist[i], slist[endPosition] = slist[endPosition], slist[i]
                    nextState = ''.join(slist)
                    if nextState not in visited:
                        nextStack.append(nextState)
                        visited.add(nextState)
                    # recover the initial state
                    slist[i], slist[endPosition] = slist[endPosition], slist[i]
            stack = nextStack
            steps += 1
        return -1
