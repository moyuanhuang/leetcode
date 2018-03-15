// 334. Increasing Triplet Subsequence
// medium
// no complicated algos!

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for(int n : nums){
            if(n < first){
                first = n;  // it's always safe to replace the current first with a smaller number
            } else if(n < second and n > first){
                second = n;
            } else if(n > second) {
                return true;
            }
        }
        return false;
    }
};
