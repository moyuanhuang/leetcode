# 692. Top K Frequent Words
# medium

# 'i', 'love', 'ii' -> 'i', 'ii', 'love'

from heapq import heappop, heappush

class Solution:
    class Element:
        def __init__(self, freq, word):
            self.word = word
            self.freq = freq
            
        def __lt__(self, other):
            if self.freq != other.freq:
                return self.freq < other.freq
            else:
                return self.word > other.word

        def __eq__(self, other):
            return self.freq == other.freq and self.word == other.word
            

    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        counter = collections.defaultdict(int)
        for word in words:
            counter[word] += 1
        heap = []
        for word, count in counter.items():
            heappush(heap, self.Element(count, word))
            if len(heap) > k:
                heappop(heap)
        result = []
        while heap:
            result.append(heappop(heap).word)
        return result[::-1]