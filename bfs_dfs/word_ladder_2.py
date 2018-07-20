# 126. Word Ladder II
# hard

import collections
import string

class Solution:
    def findLadders(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: List[List[str]]
        """
        steps = {}
        words = set(wordList)
        parents = collections.defaultdict(set)
        self.res = []
        if not endWord in words:
            return self.res

        queue = [beginWord]
        found = False
        step = 1
        while queue:
            next_set = set()
            while queue:
                cur = queue.pop(0)
                for i in range(len(cur)):
                    for ch in string.ascii_lowercase:
                        trans_word = cur[:i] + ch + cur[i+1:]
                        if trans_word == endWord:
                            found = True
                        if trans_word in words and step <= steps.get(trans_word, len(wordList)):
                            steps[trans_word] = step
                            parents[trans_word].add(cur)
                            next_set.add(trans_word)
            if found:
                self.gen_paths(parents, beginWord, endWord, [endWord])
                break
            queue = list(next_set)
            step += 1
        return self.res
    
    def gen_paths(self, parents, beginWord, cur_word, path):
        if cur_word == beginWord:
            self.res.append(path[::-1])
            return

        for next_word in parents[cur_word]:
            path.append(next_word)
            self.gen_paths(parents, beginWord, next_word, path)
            path.pop(-1)

# if __name__ == '__main__':
#     bw = "hit"
#     ew = "cog"
#     wl = ["hot","dot","dog","lot","log","cog"]
#     sol = Solution()
#     paths = sol.findLadders(bw, ew, wl)
#     for p in paths:
#         print(p)

