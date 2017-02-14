class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle)
	{
		int n = triangle.size();
		vector<int> tmp(n,0);
		for(int i = 0; i < n; i++)
			tmp[i] = triangle[n-1][i];
		for(int i = n-2; i >= 0; i--)
		{
			for(int j = 0; j < triangle[i].size(); j++)
				tmp[j] = triangle[i][j] + min(tmp[j], tmp[j+1]);
		}
		return tmp[0];
	}
};