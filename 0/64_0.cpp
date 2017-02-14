class Solution {
public:
	int minPathSum(vector<vector<int>>& grid)
	{
		int r = grid.size(); if(!r)	return 0;
		int c = grid[0].size(); if(!l)	return 0;
		vector<vector<int>> f = grid;
		for(int i = 1; i < c; i++)
			f[0][i] += f[0][i-1];
		for(int i = 1; i < r; i++)
			f[i][0] += f[i-1][0];

		for(int i = 1; i < r; i++)
			for(int j = 1; j < c; j++)
				f[i][j] += min(f[i-1][j], f[i][j-1]);

		return f[r-1][c-1];

	}
};