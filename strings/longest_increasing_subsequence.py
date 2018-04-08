# 300. Longest Increasing Subsequence
# medium
# keep a list of candidate sequences, when a new num comes, compare to the
# end of each sequence, find the index of the last sequence whose end num is
# smaller than num
# 1. if all end > num, insert a new sequence [num]
# 2. if all end < num, copy and append to the last sequence
# 3. if in the middle, copy adn append sequences[index], AND REMOVE sequences
# that has SAME LENGTH

class Solution:
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        lasts = [nums[0]]
        candidates = [[nums[0]]]
        for n in nums[1:]:
            index = self.find_first_smaller(lasts, n)
            if index == -1:
                candidates.insert(0, [n]);
                lasts.insert(0, n)
            elif index == len(lasts):
                candidates.append(candidates[-1][:] + [n])
                lasts.append(n)
            else:
                new_candidate = candidates[index][:] + [n]
                candidates.insert(index + 1, new_candidate)
                lasts.insert(index + 1, n)
                index += 2
                while len(candidates[index]) == len(new_candidate):
                    del candidates[index]
                    del lasts[index]
        return max([len(candidate) for candidate in candidates])

def find_first_smaller(lasts, n):
    for i, v in lasts:
        if v >= n:
            return i - 1;
    return len(lasts)
