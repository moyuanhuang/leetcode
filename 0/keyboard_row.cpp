// leetcode 500. Keyboard Row
// tolower
// transform(data.begin(), data.end(), data.begin(), ::tolower);

class Solution {
public:
  vector<string> findWords(vector<string>& words) {
    char row1_[10] = {'q','w','e','r','t','y','u','i','o','p'};
    char row2_[9] = {'a','s','d','f','g','h','j','k','l'};
    char row3_[7] = {'z','x','c','v','b','n','m'};
    vector<unordered_set<char> > sets(3);

    sets[0] = unordered_set<char>(begin(row1_), end(row1_));
    sets[1] = unordered_set<char>(begin(row2_), end(row2_));
    sets[2] = unordered_set<char>(begin(row3_), end(row3_));

    vector<string> ret;
    for(string w : words){
      for(auto uset : sets){
        if(isInSet(w, uset)){
          ret.push_back(w);
          break;
        }
      }
    }
    return ret;
  }

private:
  bool isInSet(string& word, unordered_set<char>& uset){
    for(char c : word){
      c = tolower(c);
      if(!uset.count(c))  return false;
    }
    return true;
  }
};
