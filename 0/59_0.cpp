class Solution {
public:
	vector<vector<int>> generateMatrix(int n)
	{
		vector<vector<int> ret(n, vector<int>(n,0));
		vector<vector<int>> dirs{{0,1}, {1,0}, {0,-1}, {-1,0}};
		vector<int> steps{n, n-1};
		int col = -1, row = 0;
		int dir = 0;
		int count = 1;
		while(steps[dir%2])
		{
			for(int i = 0; i < steps[n%2]; i++)
			{
				ret[row+dirs[dir%4][0]][col+dirs[dir%4][1]] = count++;
			}
			--steps[dir%2];
			++dir;
		}
	}
};