class Solution {
public:
  int hIndex(vector<int>& citations) {
    if(citations.empty()) return 0;
    int length = citations.size();
    vector<int> stat(length + 1);
    for(int c : citations){
      if(c >= length)
        ++stat[length];
      else
        ++stat[c];
    }

    int count = 0;
    for(int i = length ; i >= 0; --i){
      count += stat[i];
      if(count >= i) return i;
    }
    return 0;
  }
};
