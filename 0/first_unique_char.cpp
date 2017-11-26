class Solution {
public:
    int firstUniqChar(string s) {
      unordered_map<char, int> umap;
      for(int i = 0; i < s.size(); ++i){
        if(umap.count(s[i])){
          umap[s[i]] = s.size();
        }
        else
          umap[s[i]] = i;
      }

      int ret = INT_MAX;
      for(auto it : umap){
        if(it.second != s.size())
            ret = min(ret, it.second);
      }
      return ret == INT_MAX ? -1 : ret;
    }
};
