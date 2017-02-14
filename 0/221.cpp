class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix)
	{
		if(matrix.empty())	return 0;
		vector<int> dp(matrix[0].size(), 0);
		int ans = 0;
		int pre = 0;
		for(int i = 0; i < cols; i++)
		{
			for(int j = 0; j < dp.size(); j++)
			{
				int tmp = dp[j];
				if(matrix[i][j] == '1')
				{
					dp[j] = min(dp[j], dp[j-1], pre) + 1;
					ans = max(ans, dp[j]);
				}
				else dp[j] = 0;
				pre = tmp;
			}
		}
		return ans * ans;
	}
};