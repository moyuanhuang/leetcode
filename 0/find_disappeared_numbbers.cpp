// leetcode 448. Find All Numbers Disappeared in an Array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      vector<int> ret;
      for(int i = 0; i < nums.size(); ++i){
        int idx = abs(nums[i]) - 1;
        nums[idx] = nums[idx] > 0 ? -nums[idx] : nums[idx];
      }
      for(int i = 0; i < nums.size(); ++i){
        if(nums[i] > 0)
          ret.push_back(i + 1);
      }
      return ret;
    }
};
