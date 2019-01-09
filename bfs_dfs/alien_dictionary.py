# 269. Alien Dictionary
# hard

from collections import defaultdict

class Solution:
    def alienOrder(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        length = len(words)
        if not length:
            return ''

        degrees = {}
        for word in words:
            for ch in word:
                degrees[ch] = 0
        edges = defaultdict(list)

        for i in range(0, length - 1):
            w1, w2 = words[i], words[i + 1]
            j = 0
            wordLen = min(len(w1), len(w2))
            while j < wordLen:
                if w1[j] != w2[j]:
                    break
                j += 1
            if j == wordLen:
                continue
            ch1, ch2 = w1[j], w2[j]
            edges[ch1].append(ch2)
            degrees[ch2] += 1

        queue = []
        for ch, degree in degrees.items():
            if degree == 0:
                queue.append(ch)

        res = ''
        while queue:
            ch = queue.pop(0)
            res += ch
            for next_ch in edges[ch]:
                degrees[next_ch] -= 1
                if degrees[next_ch] == 0:
                    queue.append(next_ch)
        if len(res) != len(degrees):
            return ''
        else:
            return res
