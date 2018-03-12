// 566. Reshape the Matrix
// easy
// just compute for the same i, where it should be in a r * c or r' * c' matrix

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int> > ret(r, vector<int>(c, 0));
        if(nums.empty())    return ret;
        int x = nums.size(), y = nums[0].size();
        if(x * y != r * c){
            return nums;
        }
        cout << x << " " << y << endl;
        for(int i = 0; i < r * c; i++){
            ret[i / c][i % c] = nums[i / y][i % y];
        }
        return ret;
    }
};
