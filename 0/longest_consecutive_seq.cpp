// leetcode 128. longest consecutive sequence
// two solutions
// 1. convert to unordered_set(O(n)), traverse again to find consecutive
//
// 2. using unordered_map to store the left and right boundaries
// A tricky part of solution.2 is that when traversing the set,
// we only count the one WITHOUT LEFT NEIGHBOR, this allows us to
// do it in O(n)

class Solution {
public:
    // hash-map solution
    // int longestConsecutive(vector<int>& nums) {
    //   unordered_map<int, int> umap;
    //   int len = 0;
    //   for(int n : nums){
    //     if(umap.count(n) == 0){
    //       int left = umap.count(n-1) != 0 ? umap[n-1] : 0;
    //       int right = umap.count(n+1) != 0 ? umap[n+1] : 0;
    //       int sum = left + right + 1;
    //       umap[n] = sum;
    //       len = max(len, sum);
    //
    //       umap[n - left] = sum;
    //       umap[n + right] = sum;
    //     }
    //   }
    //   return len;
    // }

    // unordered_set solution
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> uset;
      for(int n : nums) uset.insert(n);
      int maxl = 0;
      for(auto it = uset.begin(); it != uset.end(); ++it){
        int n = *it;
        if(uset.find(n-1) == uset.end()){
          int left = n;
          while(uset.find(n++) != uset.end());
          int len = n - left - 1;
          maxl = max(maxl, len);
        }
      }
      return maxl;
    }
};
