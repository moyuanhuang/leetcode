class Solution {
public:
	int rob(vector<int>& nums) {
		int ans = 0;
		if(nums.size() == 0)    return ans;
		if(nums.size() == 1)    return nums[0];
		vector<int> dp(nums.size()+1,0);
		// rob the first one
		dp[1] = nums[0];
		for(int i = 2; i < dp.size()-1; i++)
		{
			int tmp = nums[i-1] + dp[i-2];
			dp[i] = tmp > dp[i-1]? tmp: dp[i-1];
		}
		ans = dp[dp.size()-2];
		// not rob the first one
		dp[1] = 0;
		for(int i = 2; i < dp.size(); i++)
		{
			int tmp = nums[i-1] + dp[i-2];
			dp[i] =  tmp > dp[i-1]? tmp: dp[i-1];
		}
		ans = ans > dp[dp.size()-1]? ans: dp[dp.size()-1];
		return ans;
	}
};