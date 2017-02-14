class Solution {
private:
	bool dfs(vector<vector<char>> board, string word, int i, int x, int y)
	{
		if(x<0 or y<0 or board[x][y] = '\0')	return false;
		if(i == word.length())	return true;

		if(board[x][y] == word[i])
		{
			board[x][y] = '\0';
			return (dfs(board, word, i+1, x+1, y) or
				dfs(board, word, i+1, x-1, y) or
				dfs(board, word, i+1, x, y+1) or
				dfs(board, word, i+1, x, y-1));
		}

	}
public:
	bool exist(vector<vector<char>>& board, string word)
	{
		if(board.empty())	return false;
		int m = board.size();
		int n = board[0].size();
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				if(dfs(board, word, 0, i, j))
					return true;
		return false;
	}
};