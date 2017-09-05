// void gameOfLife(vector<vector<int>>& board) {
//     int m = board.size(), n = m ? board[0].size() : 0;
//     for (int i=0; i<m; ++i) {
//         for (int j=0; j<n; ++j) {
//             int count = 0;
//             for (int I=max(i-1, 0); I<min(i+2, m); ++I)
//                 for (int J=max(j-1, 0); J<min(j+2, n); ++J)
//                     count += board[I][J] & 1;
//             if (count == 3 || count - board[i][j] == 3)
//                 board[i][j] |= 2;
//         }
//     }
//     for (int i=0; i<m; ++i)
//         for (int j=0; j<n; ++j)
//             board[i][j] >>= 1;
// }

class Solution {
public:
    void gameOfLife(vector<vector<int> >& board) {
      if(board.empty()) return;

      int nc = board.size();
      int nr = board[0].size();
      for(int i =0; i < nc; ++i){
        for(int j = 0; j < nr; ++j){
          int start_c = max(0, i - 1);
          int start_r = max(0, j - 1);
          int end_c = min(i + 1, nc - 1);
          int end_r = min(j + 1, nr - 1);
          cout << start_c << " " << end_c << " " << start_r << " " << end_r << endl;

          if(is_alive(board, start_c, start_r, end_c, end_r, i, j))
            board[i][j] |= 2;
        }
      }
      update(board);
      return;
    }

private:
    bool is_alive(const vector<vector<int> >& board, int sc, int sr, int ec, int er, int c, int r){
        int count = 0;
        for(int i = sc; i < ec + 1; ++i)
            for(int j = sr; j < er + 1; ++j){
                if(i == c and j == r) continue;
                if(board[i][j] & 1)
                  ++count;
            }
        cout << count << endl;
        if(count == 2 and board[c][r] & 1) return true;
        else if(count == 3) return true;
        else  return false;
    }

    void update(vector<vector<int> >& board){
      for(int i = 0; i < board.size(); ++i)
        for(int j = 0; j < board[0].size(); ++j)
          board[i][j] >>= 1;
    }

};
