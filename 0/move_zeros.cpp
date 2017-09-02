class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int cur = 0, non_zero = 0; non_zero < nums.size(); non_zero++){
            if(nums[non_zero] != 0){
                swap(nums[non_zero], nums[cur++]);
            }
        }
    }
};
