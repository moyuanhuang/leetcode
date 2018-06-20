class Solution:
    def shortestDistance(self, words, word1, word2):
        """
        :type words: List[str]
        :type word1: str
        :type word2: str
        :rtype: int
        """
        indexes_1 = []
        indexes_2 = []
        for i, word in enumerate(words):
            if word1 == word:
                indexes_1.append(i)
            elif word2 == word:
                indexes_2.append(i)

        dist = float('Inf')
        for i1 in indexes_1:
            for i2 in indexes_2:
                dist = min(dist, abs(i1 - i2))

        return dist

