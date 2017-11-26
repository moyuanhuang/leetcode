class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      unordered_set<int> uset(nums1.begin(), nums1.end());
      vector<int> ret;
      for(int n : nums2){
        if(uset.count(n)){
          ret.push_back(n);
          uset.erase(n);
        }
      }
      return ret;
    }
};
