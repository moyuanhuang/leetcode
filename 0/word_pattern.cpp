class Solution {
public:
  bool wordPattern(string pattern, string str) {
    unordered_map<char, int> p2i;
    unordered_map<string, int> s2i;
    istringstream in(str);
    int i = 0, n = pattern.size();
    for(string word; in >> word; i++){
      if(i == n || p2i[pattern[i]] != s2i[word])
        return false;
      p2i[pattern] = w2i[word] = i + 1;
    }
    return i == n;
  }
};
