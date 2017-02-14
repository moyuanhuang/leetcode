class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k)
	{
		if(nums.empty())	return false;
		unordered_map<int, int> map;
		for(int i = 0; i < nums.size(); i++)
		{
			int n = nums[i];
			if(map.count(n) != 0)
				if (map[n] - i <= k)	return true;
			else
				map[n] = i;
		}
		return false;
	}
};