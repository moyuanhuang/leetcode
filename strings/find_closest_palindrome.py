# 564. Find the Closest Palindrome
# hard

class Solution:
    def nearestPalindromic(self, S):
        size = len(S)
        candidates = [str(10**s + d) for s in [size - 1, size] for d in [-1, 1]]
        prefix = int(S[:(size + 1)//2])
        for p in map(str, (prefix - 1, prefix, prefix + 1)):
            candidates.append(p + (p[:-1] if size % 2 else p)[::-1])

        def delta(x):
            return abs(int(S) - int(x))

        ans = None
        for cand in candidates:
            if cand == S: continue
            diff = delta(cand)
            if ans is None: ans = cand
            elif diff < delta(ans):
                ans = cand
            elif diff == delta(ans) and int(cand) < int(ans):
                ans = cand
        return ans

