/* 35.Search Insert Position
 * Created by Moyuan Huang on Sep.17 2016.
*/
/*
 * O(n) Solution
class Solution {
public:
	int searchInsert(vector<int>& nums, int target)
	{
		for(int i =0; i < nums.size(); i++)
			if(target <= nums[i])	return	i;
	    return nums.size();
	}
};
*/
// O(logn) Solution
class Solution {
private:
	int binarySearch(vector<int>& nums, int begin, int end, int target)
	{
	    cout << begin << ' ' << end << endl;
		if(begin == end)
		{
		    if(target <= nums[begin])   return begin;
		    if(target > nums[begin])    return begin + 1;
		}
		int mid_pos = (begin + end)/2;
		if(target <= nums[mid_pos])	return binarySearch(nums, begin, mid_pos, target);
		else if(target > nums[mid_pos])	return binarySearch(nums, mid_pos+1, end, target);
		return end;
	}
public:
	int searchInsert(vector<int>& nums, int target)
	{
		return binarySearch(nums, 0, nums.size()-1, target);
	}
};