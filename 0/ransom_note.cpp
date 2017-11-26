class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      unordered_map<char, int> available;
      for(char c : magazine){
        if(available.count(c))
          available[c]++;
        else
          available[c] = 1;
      }

      for(char c : ransomNote){
        if(available.count(c) and available[c] > 0){
          available[c]--;
        }
        else
          return false;
      }
      return true;
    }
};
