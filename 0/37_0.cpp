/* 37. Sudoku Solver
 * Created by Moyuan Huang on Sep.20, 2016.
*/
class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++)
				if(board[i][j] != '.')
					fill(i, j, board[i][j] - '0');
		solve(board, 0);
	}
private:
	void solve(vector<vector<char>>& board, int index)
	{
		if(index >= 81)	return true;
		row = index / 9;
		col = index - i * 9;
		if(board[row][col] != '.')	return solve(row, col, index+1);
		else
		{
			for(int i = 0; i < 9; j++)
			{
				if(check(row, col, i))
				{
					board[row][col] = i;
					fill(row, col, i);
					if(solve(board, index+1))
						return true;
					clear(row, col, i);
				}	
			}
			board[row][col] = '.';
			return false;
		}

	}

	void fill(int row, int col, int val)
	{
		int k = row/3*3 + col/3;
		cols[col][val] = 1;
		rows[row][val] = 1;
		subs[k][val] = 1;
		return;
	}

	void check(int row, int col, int val)
	{
		int k = row/3*3 + col/3;
		if(rows[row][val] == 1 or cols[col][val] == 1 or subs[k][val] == 1)
			return false;
		return true;
	}

	void clear(int row, int col, int val)
	{
		int k = row/3*3 + col/3;
		cols[col][val] = 0;
		rows[row][val] = 0;
		subs[k][val] = 0;
		return;
	}

	int cols[9][9] = {0};
	int rows[9][9] = {0};
	int subs[9][9] = {0};

};