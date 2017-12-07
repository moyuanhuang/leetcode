class NumArray {
public:
    NumArray(vector<int> nums) {
        int sum = 0;
        sums.push_back(0);
        for(int n : nums){
            sum += n;
            sums.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return sums[j+1] - sums[i];
    }

private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
