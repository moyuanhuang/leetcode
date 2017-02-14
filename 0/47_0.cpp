/* 47. Permutations II
 * Created by Moyuan Huang on Sep.22, 2016. 
*/
class Solution {
private:
	void dfs(vector<int> nums, int i, vector<vector<int>> ret)
	{
		if(i == nums.size()-1)
		{
			ret.push_back(nums);
			return;
		}
		for(int j = i; j< nums.size(); j++)
		{
			if(nums[j] != nums[i])
			{
				swap(nums[j],nums[i]);
				dfs(nums, i+1, ret);
			}
		}
	}
public:
	vector<vector<int> > permuteUnique(vector<int>& nums)
	{
		vector<vector<int>> ret;
		dfs(nums, 0, ret);
		return ret;
	}
};