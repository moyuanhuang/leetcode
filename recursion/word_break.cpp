class Solution {
public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    for(int i = 0; i < s.size(); ++i){
      string prefix = s.substr(0, i + 1);
      string subfix = s.substr(i + 1);

    }
  }
};
