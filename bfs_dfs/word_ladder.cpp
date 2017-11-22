// leetcode 127. word ladder
// NEVER USE DFS!!!

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      unordered_set<string> word_dict(wordList.begin(), wordList.end());
      queue<string> to_visit;
      to_visit.push(beginWord);
      int res = 1;
      while(!to_visit.empty()){
        int len = to_visit.size();
        for(int i = 0; i < len; ++i){
          string word = to_visit.front();
          to_visit.pop();

          if(word == endWord) return res;
          find_ladder(word, word_dict, to_visit);
        }
        res++;
      }
      return 0;
    }

private:
  void find_ladder(string word, unordered_set<string>& dict, queue<string>& to_visit){
    dict.erase(word);
    for (int p = 0; p < (int)word.length(); p++) {
      char letter = word[p];
      for (int k = 0; k < 26; k++) {
        word[p] = 'a' + k;
        if (dict.find(word) != dict.end()) {
          to_visit.push(word);
          dict.erase(word);
        }
      }
      word[p] = letter;
    }
  }
};
