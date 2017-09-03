// this is the binary search solution, not an time optimal solution
// an optimal solution can be found
// [here](https://leetcode.com/problems/find-the-duplicate-number/description/)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      int size = nums.size();
      if(!size) return -1;
      int low = 1, high = size - 1;
      while(low < high){
        int mid = low + (high - low) / 2;
        int count = 0;
        for(int n : nums){
          if(n <= mid) count++;
        }
        if(count > mid) high = mid;
        else low = mid + 1;
      }
      return low;
    }
};
