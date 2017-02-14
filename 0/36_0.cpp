/* 36. Valid Sudoku
 * Created by Moyuan Huang on Sep.17 2016.
*/
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board)
	{
		int table1[9][9] = {0};
		int table2[9][9] = {0};
		int table3[9][9] = {0};
		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++)
			{
				int num = board[i][j] - '0' - 1;
				int k = i/3 * 3 + j/3 ;
				if(table1[k][num] or table2[k][num] or table[k][num])
					return false;
				table1[k][num] = table2[k][num] = table3[k][num] = 1;	
			}
		return true;
	}
};