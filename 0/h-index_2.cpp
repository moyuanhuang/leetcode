class Solution {
public:
    int hIndex(vector<int>& citations) {
      int size = citations.size();
      if(!size) return 0;
      if(size == 1) return min(size, citations[0]);

      int left = 0, right = citations.size() - 1;
      while(left < right){
        int mid = left + (right - left)/2;
        if(citations[mid] == size - mid)  return citations[mid];
        else if(citations[mid] > size - mid) right = mid;
        else  left = mid + 1;
      }
      return size - right;
    }
};
