// 324. Wiggle Sort II
// first sort, odd index stores (1, 3, 5, ...) larger half,
// even index stores (0,2,...) smaller half,
// BOTH FROM BACK TO FRONT, BECAUSE NEED TO CONSIDER A CORNER CASE
// S, S, M, M, M, M, L, L
// if from fornt to back S, M, S, M, M, L, M, L -> not valid
// but from back to front M, L, M, L, S, M, S, M -> valid

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sort.begin(), sort.end());
        int odd = 0, even = (sorted.size() + 1) / 2;
        for(int i = 0; i < nums.size(); i++){
            if(i & 1){
                nums[i] = sorted[odd++];
            }
            else {
                nums[i] = sorted[even++];
            }
        }
        return nums[i];
    }
};
