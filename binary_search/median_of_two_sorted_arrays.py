# 4. Median of Two Sorted Arrays
# hard

class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """        
        # IMPORTANT FOR UNDERSTAND:
        # 1. k start from index ZERO!
        # 2. ma and mb, we only keep ONE every recusive call
        def kth(A, B, k):
            if len(A) == 0:
                return B[k]
            if len(B) == 0:
                return A[k]

            ia, ib = len(A) // 2, len(B) // 2
            med_a, med_b = A[ia], B[ib]
            # uncomment 2 lines below to see what happens for input [1,3,5], [2,4],
            # where k = ia + ib, notice that ia + ib is the number of elements
            # BEFORE med_a and med_b, EXCLUSIVE!
            # print("A[%d] = %d\nB[%d] = %d\n\n"% (ia, med_a, ib, med_b))
            # print("A[%d] = %d\nB[%d] = %d\n\n"% (ia, med_a, ib, med_b))

            # when k is larger than the number of elements before the two medians
            if (ia + ib) < k:
                # if A's median is bigger than B's, B's first half doesn't include k
                if med_a > med_b:
                    return kth(A, B[ib +1:], k - ib - 1)
                else:
                    return kth(A[ia + 1:], B, k - ia - 1)
            # when k is smaller or equal to the number of elements before the two medians
            else:
                # if A's median is bigger than B's, A's second half doesn't include k
                if med_a > med_b:
                    return kth(A[:ia], B, k)
                else:
                    return kth(A, B[:ib], k)

        m, n = len(nums1), len(nums2)
        if (m + n) % 2 == 1:
            return kth(nums1, nums2, (m + n) // 2)
        else:
            first = kth(nums1, nums2, (m + n - 1) // 2)
            second =kth(nums1, nums2, (m + n) // 2) 
            return (first + second) / 2
