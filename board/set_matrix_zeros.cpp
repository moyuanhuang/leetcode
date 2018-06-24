// Bloomberg on campus
// leetcode 73. Set matrix zeros
// KEYWORD:
// IN-PLACE

class Solution {
public:
    // in-place solution
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return;
        int rows = matrix.size(), cols = matrix[0].size();
        bool set_col_zero = false;

        for(int i = 0; i < rows; i++){
            if(matrix[i][0] == 0)
                set_col_zero = true;
            for(int j = 1; j < cols; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < rows; i++){
            if(matrix[i][0] == 0){
                for(int j = 1; j < cols; j++)
                    matrix[i][j] = 0;
            }
        }

        for(int i = 1; i < cols; i++){
            if(matrix[0][j] == 0){
                for(int j = 1; j < rows; j++)
                    matrix[j][i] = 0;
            }
        }

        if(set_col_zero){
            for(int i = 0; i < rows; i++)
                matrix[i][0] = 0;
        }
        return;
    }

    // O(m + n) solution
    // void setZeroes(vector<vector<int>>& matrix) {
    //     if(matrix.empty())
    //         return;
    //
    //     int row = matrix.size(), col = matrix[0].size();
    //     vector<bool> column_is_set(col, false);
    //     vector<bool> row_is_set(row, false);
    //
    //     for(int i = 0; i < row; i++){
    //         for(int j = 0; j < col; j++){
    //             if(matrix[i][j] == 0){
    //                 row_is_set[i] = true;
    //                 column_is_set[j] = true;
    //             }
    //         }
    //     }
    //
    //     for(int i = 0; i < row; i++){
    //         if(row_is_set[i]) {
    //             for(int j = 0; j < col; j++){
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }
    //
    //     for(int i = 0; i < col; i++){
    //         if(column_is_set[i]) {
    //             for(int j = 0; j < row; j++){
    //                 matrix[j][i] = 0;
    //             }
    //         }
    //     }
    //     return;
    // }
};
