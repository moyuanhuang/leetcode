# 127. Word Ladder
# medium

# BFS instead of DFS, can use twi way BFS.

class Solution:
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        words = set(wordList)
        if not endWord in words:
            return 0

        steps = 1
        queue = set([beginWord])
        while queue:
            next_queue = set()
            print(len(queue))
            while queue:
                cur = queue.pop()
                if cur == endWord:
                    return steps
                for i in range(len(cur)):
                    for ch in string.ascii_lowercase:
                        trans_word = cur[:i] + ch + cur[i+1:]
                        if trans_word in words:
                            next_queue.add(trans_word)

            for word in next_queue:
                words.remove(word)
            queue = next_queue
            steps += 1
        return 0
