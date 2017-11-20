// leetcode 419
// add count only on upper-left of the ship, because we scan from upper-left corner

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
      int count = 0;
      for(int i = 0; i < board.size(); ++i){
        for(int j = 0; j < board[0].size(); ++j){
          if(board[i][j] == 'X' and (i == 0 or board[i - 1][j] != 'X') and (j == 0 or board[i][j-1] != 'X'))
            count++;
        }
      }
      return count;
    }
};

// traditional dfs
// class Solution {
// public:
//     int countBattleships(vector<vector<char>>& board) {
//       count = 0;
//       for(int i = 0; i < board.size(); ++i){
//         for(int j = 0; j < board[0].size(); ++j){
//           if(board[i][j] == 'X')
//             helper(board, i, j, false);
//         }
//       }
//       return count;
//     }
//
// private:
//   int count;
//
//   void helper(vector<vector<char>>& board, int i, int j, bool started){
//     if(!started){
//       ++count;
//       started = true;
//     }
//
//     board[i][j] = '.';
//     if(i > 0 and board[i-1][j] == 'X')  helper(board, i - 1, j, true);
//     if(i < board.size() - 1 and board[i + 1][j] == 'X') helper(board, i + 1, j, true);
//     if(j > 0 and board[i][j - 1] == 'X')  helper(board, i, j - 1, true);
//     if(j < board[0].size() - 1 and board[i][j + 1] == 'X')  helper(board, i, j + 1, true);
//     return;
//   }
};
