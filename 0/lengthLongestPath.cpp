class Solution {
public:
  int lengthLongestPath(string input) {
    int len = input.size();
    vector<int> length_at[200];
    int count = 0, level = 1, ans = INT_MIN;
    bool isFile = false;
    for(int i = 0; i < len; ++i){
      while(input[i] == '\t'){
        ++level;
        ++i;
      }
      while(i < len and input[i] != '\n'){
        if(input[i] == '.')  isFile = true;
        ++count;
        ++i;
      }
      if(isFile){
        ans = max(ans, length_at[level - 1] + count);
      }
      else{
        length_at[level] = length_at[level - 1] + count + 1;
      }
      count = 0;
      level = 1;
      isFile = false;
    }
    return ans;
  }
};
