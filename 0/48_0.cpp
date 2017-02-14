/* 48. Rotate Image
 * Created by Moyuan Huang on Sep.22, 2016. 
*/
/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
class Solution {
public:
	void rotate(vector<vector<int>>& matrix)
	{
		int n = matrix.size();
		for(int i = 0; i < n/2; i++)
			for(int j = 0; j < n; j++)
				swap(matrix[i][j], matrix[n-1-i][j]);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < i; j++)
				swap(matrix[i][j],matrix[j][i]);
	}
};