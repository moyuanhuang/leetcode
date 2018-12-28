# 881. Boats to Save People
# medium

class Solution(object):
    def numRescueBoats(self, people, limit):
        """
        :type people: List[int]
        :type limit: int
        :rtype: int
        """
        people.sort()
        count = 0
        i, j = 0, len(people) - 1
        while i <= j:
            first, second = people[i], people[j]
            if first + second <= limit:
                i += 1
                j -= 1
            else:
                j -= 1
            count += 1
        return count
