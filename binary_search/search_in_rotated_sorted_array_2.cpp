// 81. Search in Rotated Sorted Array II
// medium

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty())    return false;
        int lo = 0, hi = nums.size() - 1, mid = 0;
        while(lo < hi){
            mid = lo + (hi - lo) / 2;
            if(target == nums[lo] || target == nums[mid] || target == nums[hi]){
                return true;
            }
            if(target > nums[lo]){
                if(target < nums[mid])  hi = mid;
                else    lo = mid + 1;
            } else if (target < nums[hi]) {
                if(target > nums[mid])  lo = mid + 1;
                else    hi = mid;
            } else {
                return false;
            }
        }
        return nums[lo] == target ? true : false;
    }
};
