class Solution {
public:
  string reverseWords(string s) {
    for(int i = 0; i < s.size(); i++){
      int start = i;
      while(i < s.size() and s[i] != ' ') i++;
      reverse(s.begin() + start, s.begin() + i);
    }
    return s;
  }
};
