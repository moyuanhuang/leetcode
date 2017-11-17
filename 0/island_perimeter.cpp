class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
      int ret = 0;
      for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[0].size(); ++j){
          if(grid[i][j]){
            if(i == 0 or grid[i - 1][j] != 1)  ret++;
            if(i == grid.size() - 1 or grid[i + 1][j] != 1)  ret++;
            if(j == 0 or grid[i][j - 1] != 1)  ret++;
            if(j == grid[0].size() - 1 or grid[i][j + 1] != 1) ret++;
          }
        }
      }
      // cout << ret << endl;
      return ret;
    }
};
