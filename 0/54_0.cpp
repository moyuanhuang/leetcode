class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
		vector<int> ret;
		rows = matrix.size();	if not (rows)	return ret;
		cols = matrix[0].size();	if not(cols)	return ret;

		vector<int> steps{cols, rows-1}

		int dir = 0;
		int ic = -1, ir = 0;
		while(steps[dir%2])
		{
			for(int i = 0; i < steps[dir%2]; i++)
			{
				ir += dirs[dir%4][0];
				ic += dirs[dir%4][1];
				ret.push_back(matrix[ir][ic]);
			}
			steps[dir%2]--;
			dir++;
		}
	}
};