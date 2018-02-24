// 153. Find Minimum in Rotated Sorted Array
// medium
// basic binary search
// corner case: nums.size() == 0 || nums.size() == 1 || ascending array(non-rotated)

class Solution {
public:
	int findMin(vector<int>& nums)
	{
		if(nums.empty())	return 0;
		int last = nums[nums.size() - 1];
		int lo = 0, hi = nums.size() - 1;
		while(lo < hi){
			int mid = lo + (hi - lo) / 2;
			if(nums[mid] > nums[mid + 1])
				return nums[mid + 1];
			if(nums[mid] > last){
				lo = mid + 1;
			}
			else{
				hi = mid;
			}
		}
		// the program didn't return in the loop only if nums[mid] always less
		// than last. which means the array is still in ascending order, i.e.
		// [0,1,2,3]
		return nums[hi];
	}
};
