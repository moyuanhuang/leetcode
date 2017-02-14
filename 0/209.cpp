class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums)
	{
		if(nums.size() == 0)	return 0;
		int start = 0, end = 0;
		int sum = 0;
		int ans = INT_MAX;
		for(; end < nums.size(); end++)
		{
			sum += nums[end];
			if(sum >= s)	
			{
				while(start <= end)
					if(sum - nums[start] >= s)
					{
					    sum -= nums[start];
						start++;
					}
					else
					    break;
				ans = ans > (end - start + 1)? end-start+1: ans;
			}
		}
		if(sum < s) ans = 0;
		return ans;
	}
};