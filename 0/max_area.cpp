// leetcode 695. Max Area of Island
// medium. just dfs

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret = 0;
        int cur = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    cur = 0;
                    helper(grid, i, j, cur, ret);
                }
            }
        }
        return ret;
    }

    void helper(vector<vector<int> >& grid, int x, int y, int& cur, int& ret){
        grid[x][y] = 0;
        cur++;
        // printf("grid[%d][%d], current_area = %d\n", x, y, cur);
        if(x > 0 and grid[x-1][y] == 1){
            // printf("grid[%d][%d] = %d\n", x - 1, y, grid[x-1][y]);
            helper(grid, x - 1, y, cur, ret);
        }
        if(x < grid.size() - 1 and grid[x+1][y] == 1){
            // printf("grid[%d][%d] = %d\n", x + 1, y, grid[x+1][y]);
            helper(grid, x + 1, y, cur, ret);
        }
        if(y < grid[0].size() - 1 and grid[x][y+1] == 1){
            helper(grid, x, y + 1, cur, ret);
        }
        if(y > 0 and grid[x][y-1] == 1){
            helper(grid, x, y - 1, cur, ret);
        }

        ret = max(ret, cur);
    }
};
