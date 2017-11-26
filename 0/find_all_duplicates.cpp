// leetcode 442. Find All Duplicates in an Array
// use the idea of encoding, set nums[i] to -nums[i] to indicate that i is already in this vector

class Solution {
public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ret;
    for(int i = 0; i < nums.size(); i++){
      int idx = abs(nums[i]) - 1;  // the -1 is the most important code in this problem!!!
      if(nums[idx] > 0)
        nums[idx] = -nums[idx];
      else
        ret.push_back(abs(nums[i]));
    }
    return ret;
  }
};
