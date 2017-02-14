class Solution {
private:
	void dfs(vector<int> nums, int index, vector<vector<int>>& ret, vector<int> cur)
	{
		if(index == nums.size())
		{
			ret.push_back(cur);
			return;
		}
		dfs(nums, index + 1, ret, cur);
		cur = cur.push_back(nums[index]);
		dfs(nums, index + 1, ret, cur);
		return;
	}
public:
	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>> ret;
		vector<int> cur;
		dfs(nums, 0, ret, cur);
		return ret;
	}
};