/* 51. N-Queens
 * Created by Moyuan Huang on Oct.10th, 2016.
*/
class Solution {
private:
	void dfs(vector<vector<string>>& ret, int n, int row, vector<string> cur, vector<vector<int>> available)
	{
		if(row >= n)
		{
		    for(int j = 0; j < n; j++)
			    cout << cur[j] << " ";
			cout << endl;
			ret.push_back(cur);
			return;
		}
		else
		{
			for(int i = 0; i < n; i++)
			{
				if(available[i] == 1)
				{
					vector<vector<int>> temp = available;
					disable(temp, row, i);
					dfs(ret, n, row+1, cur, temp);
				}
			}
		}
		return;
	}

	void disable(vector<vector<int>>& available, int row, int col)
	{
		for(int i = row, j = col; i >= 0 and j >=0; i--, j--)
			available[i][j] = 0;
		for(int i = row, j = col; i <n 0 and j <0; i++, j++)
			available[i][j] = 0;
		for(int i = 0; i < n; i++)
			available[i][col] = 0;
		return;
	}

public:
	vector<vector<string>> solveNQueens(int n)
	{
		vector<vector<string>> ret(n, vector<string>(n, string(4, '.')));
		vector<string> cur(n, string(4, '.'));
		vector<vector<int>> available(n, vector<int>(n, 1));
		dfs(ret, n, 0, cur, available);
		return ret;
	}
};