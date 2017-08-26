class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int res = num\.size();
    for (int i = 0; i < nums.size(); i++) {
      res ^= nums[i];
      res ^= i;
    }
    return res;
  }
};
