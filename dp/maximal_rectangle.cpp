// leetcode 85
// two valid solutions
// 1. dp
// 2. histogram

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
      if(matrix.empty()) return 0;
      const int m = matrix.size();
      const int n = matrix[0].size();
      int left[n], right[n], height[n];  // only need 1-d array to store row by row
      fill_n(left, n, 0);
      fill_n(right, n, n);
      fill_n(height, n, 0);

      int maxA = 0;
      for(int i = 0; i < m; ++i){
        int cur_left = 0, cur_right = n;
        for(int j = 0; j < n; ++j){
          if(matrix[i][j] == '1') height[j]++;
          else  height[j] = 0;
        }

        for(int j = 0; j < n; ++j){
          if(matrix[i][j] == '1') left[j] = max(cur_left, left[j]);
          else{
            left[j] = 0;
            cur_left = j + 1; // this is easy to forget, update cur_left only if current position has 0
          }
        }

        for(int j = n - 1; j >= 0; --j){
          if(matrix[i][j] == '1') right[j] = min(cur_right, right[j]);
          else{
            right[j] = n;
            cur_right = j;  // instead of j - 1, because right is exclusive, otherwise right - left will be 0
          }
        }

        for(int j = 0; j < n; ++j){
          maxA = max(maxA, (right[j] - left[j]) * height[j]);
        }
      }
      return maxA;
    }
};
