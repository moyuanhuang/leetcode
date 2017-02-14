class Solution {
public:
	int findPeakElement(vector<int>& nums)
	{
		if(nums.empty())	return 0;
		if(nums.size() == 1)	return 0;
		return helper(nums, 0, nums.size()-1);
	}

	int helper(vector<int>& nums, int start, int end)
	{
		if(start == end)
			return start;
		if(start + 1 == end)
		    return nums[start] > nums[end]? start: end;
		int mid = (start+end)/2;
		if(nums[mid-1] < nums[mid] and nums[mid] > nums[mid+1])
			return mid;
		if(nums[mid-1] < nums[mid] and nums[mid] < nums[mid+1])
			return helper(nums, mid+1, end);
		else
			return helper(nums, start, mid-1);
		return -1;
	}
};