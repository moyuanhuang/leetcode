/* 41. First Missing Positive
 * Created by Moyuan Huang on Sep.22, 2016. 
*/
class Solution {
public:
	int firstMissingPositive(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		int count = 1;
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] <= 0)	continue;
			else
			{
				if(count == nums[i])
				{
				    count++;
				    while(i < nums.size() - 1 and nums[i] == nums[i+1]) i++;
				}
				else    return count;
			}
		}
		return count; 

	}
};