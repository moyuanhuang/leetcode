class Solution {
public:
	void solve(vector<vector<char>>& board)
	{
		if(board.empty())	return;
		int row = board.size(), col = board[0].size();
    
		for(int i = 0; i < col; i++)
		{
		    helper(0, i, board);
		    if(row > 1)
		        helper(row-1, i, board);
		}
		for(int i = 0; i < row; i++)
		{
		    helper(i, 0, board);
		    if(col > 1)
		        helper(i, col-1, board);
		    
		}
		for(int i = 0; i < row; i++)
			for(int j = 0; j < col; j++)
			{
				if(board[i][j] == 'O')	board[i][j] = 'X';
				if(board[i][j] == '1')	board[i][j] = 'O';
			}
		return;
	}

	void helper(int r, int c, vector<vector<char>>& board)
	{
// 		if(r >= board.size() or c >= board[0].size() or c < 0 or r < 0)	return;
// 		cout << r << "<" << board.size() << "   " << c << "<" << board[0].size() << endl;
		if(board[r][c] == 'O')
		{
			board[r][c] = '1';
			if(r > 1)    helper(r-1, c, board);
			if(r < board.size() -1)    helper(r+1, c, board);
			if(c > 1)    helper(r, c-1, board);
			if(c < board[0].size() - 1)    helper(r, c+1, board);
		}
		return;
	}
};