// leet code 540
// think about how to handle the case where index is odd
// shoud check index - 1 && index instead of index + 1 && index + 2

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      int lo = 0, high = nums.size()/2 - 1;
      while(lo < high){
        int mid = lo + (high - lo)/2;
        int even = mid % 2 == 0 ? nums[mid] : nums[mid - 1];
        int odd = mid % 2 == 0 ? nums[mid + 1] : nums[mid];
        if(even == odd){
          lo = mid + 1;
        }
        else
          high = mid;
      }
      return nums[mid / 2 * 2];
    }
};

// cheating
// int singleNonDuplicate(vector<int>& nums) {
//   int ret = 0;
//   for(int n : nums){
//     ret ^= n;
//   }
//   return ret;
// }
