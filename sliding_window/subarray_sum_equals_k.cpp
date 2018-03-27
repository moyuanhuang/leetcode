// 560. Subarray Sum Equals K
// medium
// think top-left corner matrix in image processing

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sums(nums);
        for(int i = 1; i < sums.size(); i++){
            sums[i] += sums[i - 1];
        }
        int count = 0;
        sums.insert(sums.begin(), 0);
        for(int i = 1; i < sums.size(); i++){
            for(int j = 0; j < i; j++){
                if(sums[i] - sums[j] == k){
                    count++;
                }
            }
        }
        return count;
    }
};
