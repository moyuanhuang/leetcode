class Solution {
public:
	int majorityElement(vector<int>& nums)
	{
		unordered_map<int, int> cnt;
		int max_cnt = 0;
		int ans = INT_MIN;
		for(int i = 0; i < nums.size(); i++)
		{
			if(cnt.count(nums[i]) > 0)
				cnt[nums[i]]++;
			else
				cnt[nums[i]] = 1;
			if(cnt[nums[i]] >= max_cnt)
			{
				ans = nums[i];
				max_cnt = cnt[nums[i]];
			}
		}
		return ans;

	}
};
