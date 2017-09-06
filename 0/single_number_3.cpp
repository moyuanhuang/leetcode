class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    vector<int> ans;
    unordered_map<int, int> umap;
    for(int n : nums){
      if(umap.count(n) == 0)
        umap[n] = 1;
      else
        --umap[n];
    }
    for(auto pair : umap){
      if(pair.second != 0)
        ans.push_back(pair.first);
    }
    return ans;
  }
};
