// leetcode 33. Search in Rotated Sorted Array
// binary search

class Solution {
public:
    int search(vector<int>& nums, int target) {
      if(nums.empty())  return -1;
      int lo = 0, hi = nums.size()-1, mid;
      while(lo < hi){
        mid = lo + (hi - lo) / 2;
        if(nums[mid] == target)
          return mid;
        else{
          if(target >= nums[0]){
            if(nums[mid] < nums[0] or nums[mid] > target)
              hi = mid;
            else
              lo = mid + 1;
          }
          else{
            if(nums[mid] > nums[0] or nums[mid] < target)
              lo = mid + 1;
            else
              hi = mid;
          }
        }
      }
      return nums[lo] == target ? lo : -1;
    }
};
