class Solution {
private:
	void generate(vector<vector<int>>& ret, vector<int> nums, int index, vector<int> cur)
	{
		if(index == nums.size())
		{
			ret.push_back(cur);
			return;
		}
		int bound = index;
		while(bound < nums.size() and nums[index] == nums[bound])
			bound++;
		for(int i = 0; i <= bound - index)
		{
			generate(ret, nums, bound, cur);
			cur.push_back(nums[index]);
		}
	}
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums)
	{
		vector<vector<int>> ret;
		sort(nums.begin(),nums.end());
		if(nums.empty())	return ret;
		vector<int> cur;
		generate(ret, nums, index, cur);
		return ret;
	}
};