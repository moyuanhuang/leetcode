// 154. Find Minimum in Rotated Sorted Array II
// hard
// 可以每种情况都分析一遍，但更简单的方法是利用nums[left]减少情况总数

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty())    return 0;
        int hi = nums.size() - 1, lo = 0;

        while(lo < hi){
        // while (nums[l] >= nums[r]) { // 如果用invariant的思想
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            if(nums[mid] == nums[lo] and nums[mid] == nums[hi]){
                return linear_search(nums);
            }
            if(nums[mid] > nums[hi])
                lo = mid + 1;
            if(nums[mid] <= nums[hi]){
                hi = mid;
            }
        }
        return nums[hi];
    }

private:
    int linear_search(vector<int>& nums){
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i + 1]){
                return nums[i + 1];
            }
        }
        return nums[0];
    }
};
