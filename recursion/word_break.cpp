// leetcode 139. Work Break
// use bfs is time consuming
// use DP !!!

// dp[i]: word(0, i - 1) can be broke
// j : length of previous word
// dp[i] = true if
//   word(0, j - 1) can break and word(j, i) is in Dict for some j

// i \in [0, s.size()]
// j \in [0, i]

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      vector<bool> dp(s.size() + 1, false);
      dp[0] = true;
      unordered_set<string> uset(wordDict.begin(), wordDict.end());

      for(int i = 0; i < s.size(); i++){
          for(int j = i; j > 0; j--){
              string word = s.substr(j, i - j + 1);
              if(dp[j] && uset.count(word) > 0){
                  dp[i + 1] = true;
                  break;
              }
          }
      }
      return dp[s.size()];
    }
};
