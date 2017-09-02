class Solution {
public:
  int hIndex(vector<int>& citations) {
    int low = 0, high = citations.size();
    int total = citations.size()
    while(low < high){
      int mid = low + (high - low) / 2;
      count = high - mid + 1;
      if(count >= citations[mid])
        low = mid + 1;
      else
        high = mid;
    }
    if((high - low + 1) < citations[low])
      return citations[low - 1];
    else
      return citations[low];
  }
};
