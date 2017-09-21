class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
      if(nums.empty())  return 0;
      int size = nums.size();
      vector<int> sum(size);
      sum[0] = nums[0];
      for(int i = 1; i < nums.size(); ++i)
        sum[i] += sum[i-1] + nums[i];
      unordered_map<int, int> umap;
      umap[sum[0]] = 0;
      int max_length = umap[0] == k? 1 : 0;
      for(int i = 1; i < nums.size(); ++i){
        if(sum[i] == k){
          max_length = max(i + 1, max_length);
          continue;
        }
        int finding = sum[i] - k;
        if(umap.find(finding) != umap.end()){
          max_length = max(i - umap[finding], max_length);
        }
        else{
          umap[sum[i]] = i;
        }
      }
      return max_length;
    }
};
