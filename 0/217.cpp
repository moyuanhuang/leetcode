class Solution {
public:
	bool containsDuplicate(vector<int>& nums)
	{
		if(nums.empty())	return true;
		unordered_map<int, int> map;
		for(int n : nums)
		{
			if(map.count(n) != 0)
				return false;
			map[n] = 1;
		}
		return true;
	}
};