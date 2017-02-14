/* 53. Maximum Subarray
 * Created by Moyuan Huang on Oct.10th, 2016.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	vector<int> arr(nums.size(), 0);
    	arr[0] = nums[0];
        int max = arr[0];
        for(int i = 1; i < nums.size(); i++)
        {
        	arr[i] = arr[i] + (arr[i-1] < 0? 0: arr[i-1])
        	max = arr[i] > max? arr[i]: max;
        }
        return max;
    }
};