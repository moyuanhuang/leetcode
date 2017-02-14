class Solution {
public:
	int findMin(vector<int>& nums)
	{
		if(nums.empty())	return 0;
		if(nums.size() == 1)	return nums[1];
		for(int i = 1; i < nums.size(); i++)
		{
			if(nums[i-1] > nums[i])	return nums[i];
		}
		return 0;
	}
};