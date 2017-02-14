class Solution {
private:
	int max(int a, int b)
	{
		return a>b? a:b;
	}
	int min(int a, int b)
	{
		return a<b? a:b;
	}
public:
	int maxProduct(vector<int>& nums)
	{
		if(nums.empty())	return 0;
		int maxpre = nums[0];
		int minpre = nums[0];
		int ans = nums[0];
		int maxlocal, minlocal;
		for(int i = 1; i < nums.size(); i++)
		{
			maxlocal = max( max(maxpre* nums[i], minpre * nums[i]), nums[i]);
			minlocal = min( min(maxpre* nums[i], minpre * nums[i]), nums[i]);
			ans = max(ans, maxlocal);
			maxpre = maxlocal;
			minpre = minlocal;
		}
		return ans;
	}
};