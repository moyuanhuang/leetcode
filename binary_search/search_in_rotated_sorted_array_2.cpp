// 81. Search in Rotated Sorted Array II
// medium

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty())    return false;
        int lo = 0, hi = nums.size() - 1, mid = 0;
        while(lo < hi){
            mid = lo + (hi - lo) / 2;
            printf("nums[%d] = %d\n", mid, nums[mid]);
            if(target == nums[lo] || target == nums[mid] || target == nums[hi]){
                return true;
            }
            if(target > nums[lo]){
                if(target < nums[mid] || nums[mid] <= nums[hi])  hi = mid;
                else    lo = mid + 1;
            } else if (target < nums[hi]) {
                if(target > nums[mid] || nums[mid] >= nums[lo])  lo = mid + 1;
                else    hi = mid;
            } else {
                return false;
            }
        }
        return nums[lo] == target ? true : false;
    }
};
// Here is another version which moves the right pointer one step forward when
// nums[mid] == nums[r], as we don’t know target is in left part or in right part:

// def search(self, nums, target):
//     if not nums:
//         return False
//     l, r = 0, len(nums)-1
//     while l < r:
//         mid = l + (r-l)//2
//         if nums[mid] == target:
//             return True
//         if nums[mid] < nums[r]:
//             if nums[mid] < target <= nums[r]:
//                 l = mid + 1
//             else:
//                 r = mid - 1
//         elif nums[mid] > nums[r]:
//             if nums[l] <= target < nums[mid]:
//                 r = mid - 1
//             else:
//                 l = mid + 1
//         else:
//             r -= 1
//     return nums[l] == target
