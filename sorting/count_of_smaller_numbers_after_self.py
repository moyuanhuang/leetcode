# 315. Count of Smaller Numbers After Self
# hard

class Solution:
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def mergeSort(arr):
            mid = len(arr) // 2

            if not mid:
                return arr

            left = mergeSort(arr[:mid])
            right = mergeSort(arr[mid:])

            i, j = 0, 0
            rightMergedCount = 0
            mergedArr = []
            while i < len(left) and j < len(right):
                if left[i][0] <= right[j][0]:
                    left[i][1] += rightMergedCount
                    mergedArr.append(left[i])
                    i += 1
                else:
                    mergedArr.append(right[j])
                    rightMergedCount += 1
                    j += 1

            if i == len(left):
                mergedArr += right[j:]
            elif j == len(right):
                for elem in left[i:]:
                    elem[1] += rightMergedCount
                    mergedArr.append(elem)

            return mergedArr

        result = [0] * len(nums)
        # corner case: nums = []
        if not nums:
            return result

        expanded_nums = []
        for i, n in enumerate(nums):
            expanded_nums.append([n, 0, i])

        # execute
        sortedNums = mergeSort(expanded_nums)

        # update result
        for elem in sortedNums:
            index = elem[2]
            result[index] = elem[1]

        return result
