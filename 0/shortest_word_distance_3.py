class Solution:
    def shortestWordDistance(self, words, word1, word2):
        """
        :type words: List[str]
        :type word1: str
        :type word2: str
        :rtype: int
        """
        
        i1 = -1
        i2 = -1

        dist = len(words) - 1
        
        for i, w in enumerate(words):
            if word1 == word2 and w == word1:
                if i1 >= 0:
                    dist = min(abs(i - i1), dist)
                i1 = i
                continue
            if w == word1:
                i1 = i
            elif w == word2:
                i2 = i
            if i1 >= 0 and i2 >= 0:
                dist = min(dist, abs(i1 - i2))
        return dist
