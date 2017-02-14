/* 16. 3Sum Closest
 * Created by Moyuan Huang on Sep.2, 2016.
*/
class Solution {
public:

    int threeSumClosest(vector<int>& nums, int target) 
    {
    	int size = nums.size();
    	if(size < 3)	return 0;
    	sort(nums.begin(), nums.end());
        // cout << endl;
    	int min = INT_MAX;
    	for(int i = 0; i < size; i++)
    	{
    		int l = i + 1, r = size - 1;	
    		while(l < r)
    		{
    			int a = nums[i] + nums[l] + nums[r] - target;
    			if(a == 0)	return target;
    			else if(a < 0)
    			{
    			    while(r > l and nums[l] == nums[l+1])	l++;
    				l++;
    			}
    			else
    			{
    			    while(r > l and nums[r] == nums[r-1])	r--;
    				r--;
    			}
    			min = abs(min) > abs(a)? a : min;
    		}
    		while( i < size - 2 and nums[i] == nums[i+1])	i++;
    	}
    	return min + target;
    }
};