/* 18. 4Sum
 * Created by Moyuan Huang on Sep.3, 2016.
*/
class Solution {
private:
	void KSum(int k, vector<int>& nums, int l, int r, int target, vector<vector<int>>& retVal, vector<int>& cur, int ci)
	{
		int i, mn, mx;
		int km1 = k - 1;

		if( r - l + 1 < k)	return;

		while(l < r)
		{
			mn = nums[l];
			mx = nums[r];

			if((mn + km1 * mx) < target)	l++;
			else if((mx + km1 * mn) > target)	r--;
			else if(k * mn > target)	break;
			else if(k * mn == target)
			{
				if( l + km1 <= r and mn == nums[l + km1])
				{
					for( i = 0; i < k; i++)	cur[ci + i] = mx;
					retVal.push_back(cur);
				}
				break;
			}
			else if(k * mx < target)	break;
			else if(k * mx == target)
			{
				if( r - km1 >= l and mx == nums[r - km1])
				{
					for( i = 0; i < k; i++)	cur[ci + i] = mx;
					retVal.push_back(cur);
				}
				break;
			}
			// if the if-else reaches here, it means target !< mn + mx !< target, which indicates mn + mx == target
			else if(k == 2)
			{
				cur[ci] = mn;
                cur[ci+1] = mx;
                retVal.push_back( cur );
				while(l < r and nums[l+1] == mn)	l++;
				l++;
				while(l < r and nums[r-1] == mx)	r--;
				r--;
			}
			else
			{
				cur[ci] = mn;
				KSum(km1, nums, ++l, r, target - mn, retVal, cur, ci+1);
				while(l < r and nums[l] == nums[l-1])	l++;
			}
		}
	}
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> retVal;
        vector<int> cur(4, 0);

        sort(nums.begin(), nums.end());
        KSum(4, nums, 0, nums.size() - 1, target, retVal, cur, 0);
        return retVal;
    }
};