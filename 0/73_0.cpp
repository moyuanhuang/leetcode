class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix)
	{
		int m = matrix.size();	if(!m)	return;
		int n = matrix[0].size();	if(!n)	return;
		vector<int> rows(m, 1);
		vector<int> cols(n, 1);
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				if(matrix[i][j] == 0)
				{
					rows[i] = 0;
					cols[j] = 0;
				}
		for(int k = 0; k < m; k++)
			if(rows[k] == 0)
				for(int i = 0; i < n; i++)
					matrix[k][i] = 0;
		for(int k = 0; k < n; k++)
			if(cols[k] == 0)
				for(int i = 0; i < m; i++)
					matrix[i][k] = 0;
		return;
	}
};