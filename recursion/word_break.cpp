class Solution {
public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> uset(wordDict.begin(), wordDict.end());
    vector<string> ret;
    helper(s, 0, wordDict, ret, string(""));
    return ret;
  }

private:
  void helper(string& s, int start, unordered_set<string>& wordDict, vector<string>& ret, string cur){
    if(start == s.size()){
      ret.push_back(cur);
      return;
    }
    for(int len = 1; len <= s.size() - start; ++len){
      string word = s.substr(start, len);
      if(wordDict.count(word)){
        string tmp = cur.empty() ? cur + word : cur + " " + word;
        helper(s, start + len, wordDict, ret, tmp);
      }
    }
    return;
  }
};
