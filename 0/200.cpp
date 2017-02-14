class Solution {
public:
	int numIslands(vector<vector<char>>& grid)
	{
		if(grid.empty())	return 0;
		int ans = 0;
		int r = grid.size(), c = grid[0].size();
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
				if(grid[i][j] == '1')
				{
					ans++;
					helper(grid, i, j);
				}
		return ans;
	}
private:
	void helper(vector<vector<char>>& grid, int i, int j)
	{
		grid[i][j] = '0';
		if(i > 0 and grid[i-1][j] == '1')	helper(grid, i-1, j);
		if(j > 0 and grid[i][j-1] == '1')	helper(grid, i, j-1);
		if(i+1 < grid.size() and grid[i+1][j] == '1')	helper(grid, i+1, j);
		if(j+1 < grid[0].size() and grid[i][j+1] == '1')	helper(grid, i, j+1);
		return;
	}
};