class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		if(matrix.empty()) return false;
		int m = matrix.size(), n = matrix[0].size();
		int bg = 0, end = m*n-1;
		while(bg <= end)
		{
		    int piv = bg + (end-bg)/2;
		  //  int mid = matrix[piv/n][piv%n];
		    if(matrix[piv/n][piv%n] > target)
		        end = piv - 1;
		    else if(matrix[piv/n][piv%n] < target)
		        bg = piv + 1;
		    else
		        return true;
		}
		return false;

	}
};