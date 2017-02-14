/* 34. Search for a Range
 * Created by Moyuan Huang on Sep.17, 2016.
*/ 
class Solution {
private:
	void search(vector<int>& nums, int begin, int end, int target, vector<int>& res)
	{
	    cout << begin << ' ' << end << endl;
		if(begin == end)
		{
		    if(res[0] == -1)    res[0] = begin;
			if(nums[begin] == target)
			{
				res[0] = res[0] > begin ? begin : res[0];
				res[1] = res[1] > begin ? res[1] : begin;
			}
			return;
		}
		int mid_pos = (begin + end)/2;
		int mid = nums[mid_pos];
		if(target <= mid)
			search(nums, begin, mid_pos, target, res);
		if(target >= mid)
			search(nums, mid_pos + 1, end, target, res);
		return;
	}
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		vector<int> res(2, -1);
		search(nums, 0, nums.size()-1, target, res);
		return res;
	}
};