// 628. Maximum Product of Three Numbersclass

Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int temp1 = nums[len - 1] * nums[len - 2] * nums[len - 3];
        int temp2 = nums[0] * nums[1] * nums[len - 1];
        return max(temp1, temp2);
    }
};
