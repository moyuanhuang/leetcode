class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
      if(nums.empty())  return 0;
      int size = nums.size();
      for(int i = 1; i < size; ++i)
        nums[i] += nums[i+1];
      unordered_map<int, int> umap;
      umap[0] = -1;
      int max_length = 0;
      for(int i = 0; i < size; ++i){
        if(umap.find(nums[i] - k) != umap.end())
          max_length = max(i - umap[nums[i] - k], max_length);
        if(umap.find(nums[i]) == umap.end())
          umap[nums[i]] = i;
      }
      return max_length;
    }
};
