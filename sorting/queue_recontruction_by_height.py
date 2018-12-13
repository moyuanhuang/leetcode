# 406. Queue Reconstruction by Height
# medium

from functools import cmp_to_key

class Solution:
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        def cmp(a, b):
            if a[0] == b[0]:
                if a[1] > b[1]:
                    return 1
                else:
                    return -1
            elif a[0] > b[0]:
                return 1
            else:
                return -1
            
        length = len(people)
        people.sort(key=cmp_to_key(cmp))

        for i in range(length - 1, -1, -1):
            person = people[i]
            count, j = person[1], i - 1
            if count == 0:
                continue
            while j >= 0 and people[j][0] == person[0]:
                count -= 1
                j -= 1

            people.pop(i)
            people.insert(i + count, person)
            # print(people)

        return people
