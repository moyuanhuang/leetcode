class Solution {
public:
	int maximumGap(vector<int>& nums)
	{
		if(nums.empty() or nums.size() < 2)	return 0;
		int min = INT_MAX, max = INT_MIN;
		for(int i = 0; i < nums.size(); i++)
		{
			min = min>nums[i]? nums[i]:min;
			max = max < nums[i] ? nums[i]: max;
		}
		int gap = (max - min)/(nums.size()- 1) + 1;
		vector<int> buc_max(nums.size()-1, INT_MIN);
		vector<int> buc_min(nums.size()-1, INT_MAX);
		for(int i = 0; i < nums.size(); i++)
		{
		    if(nums[i] == min or nums[i] == max)
		        continue;
			int idx = (nums[i]-min) / gap;
			buc_min[idx] = buc_min[idx] > nums[i]? nums[i]: buc_min[idx];
			buc_max[idx] = buc_max[idx] > nums[i]? buc_max[idx]: nums[i];
		}
		int prev = min;
		int max_gap = INT_MIN;
		for(int i = 0; i < nums.size()-1; i++)
		{
			if(buc_max[i] == INT_MIN and buc_min[i] == INT_MAX)	continue;
			max_gap = max_gap > (buc_min[i] - prev) ? max_gap: (buc_min[i] - prev);
			prev = buc_max[i];
		}
		max_gap	= max_gap > (max - prev)? max_gap: (max - prev);
		return max_gap;
	}
};
