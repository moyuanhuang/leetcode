class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
	{
		int rows = obstacleGrid.size();
		if(!rows)	return 0;
		int cols = obstacleGrid[0].size();
		if(!cols)	return 0;

		vector<vector<int>> ways(rows, vector<int>(cols, 0));
		for(int i = 0; i < cols; i++)
		{
			if(obstacleGrid[0][i] == 1)	break;
			ways[0][i] = 1;
		}
		for(int i = 0; i < rows; i++)
		{
			if(obstacleGrid[i][0] == 1)	break;
			ways[i][0] = 1;
		}

		for(int i = 1; i < rows; i++)
			for(int j = 1; j < cols; j++)
				if(obstacleGrid[rows][cols] != 1)
					ways[rows][cols] = ways[rows-1][cols] + ways[rows][cols-1];
				else
					ways[rows][cols] = 0;

		return ways[rows-1][cols-1];
	}
};