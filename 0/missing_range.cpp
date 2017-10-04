class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
      vector<string> ans;
      if(lower > upper) return ans;
      int next = lower;
      for(int i : nums){
        if(i < next) continue;
        if(i == next){
          next++;
          continue;
        }
        int right = i - 1;
        ans.push_back(getRange(next, right));
        next = i + 1;
      }
      if(next <= upper) ans.push_back(getRange(next, upper));
      return ans;
    }

private:
  string getRange(int left, int right){
    cout << "generating range" << left << " to " << right << endl;
    char str[20];
    sprintf(str, "%d->%d", left, right);
    return left == right? to_string(left) : string(str);
  }

};
