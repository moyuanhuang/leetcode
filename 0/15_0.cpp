/*
 * 15. 3Sum
 * Created by Moyuan Huang on 8/27/2016
*/
#include "Solution.h"
using namespace std;

/*class Solution {
public:*/
	vector<vector<int> > Solution::threeSum(vector<int>& nums)
	{
		vector<vector<int> >	result;
		if(nums.size() < 3)
			return result;
		sort(nums.begin(), nums.end());
    	for(int i = 0; i < nums.size(); i++)
    	{
    	    int j = i + 1;
    	    int k = nums.size() - 1;
    		while(j < k)
    		{
    		    if( nums[i] + nums[j] + nums[k] == 0)
    		    {
    		        vector<int> triplet;
    		        triplet.push_back(nums[i]);
    			    triplet.push_back(nums[j]);
    				triplet.push_back(nums[k]);
    				result.push_back(triplet);
    				while( j < k and nums[j] == nums[j+1]) ++j;
    		        while( j < k and nums[k] == nums[k-1]) --k;
    		        j++;
    		        k--;
    		    }
    		    else if( nums[i] + nums[j] + nums[k] < 0)
    		        j++;
    		    else if( nums[i] + nums[j] + nums[k] > 0)
    		        k--;
    		}
    		while(i < nums.size() -1 and nums[i] == nums[i+1])  i++;
    	}
    	return result;
	}
//};
