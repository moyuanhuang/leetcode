/* 45. Jump Game II
 * Created by Moyuan Huang on Sep.25, 2016.
*/
class Solution {
public:
	int jump(vector<int>& nums)
	{
		int ret = 0;
		int i = 0;
		while(i < nums.size() - 1)
		{
			int range = nums[i];
			int max = -1;
			int maxInd = 0;
			for(int j = 1; j <= range; j++)
			{
				int reachOut = i + j + nums[i + j];
				if(reachOut >= nums.size() - 1)	return ret++;
				if(reachOut >= max)
				{
					max = reachOut;
					maxInd = i + j;
				}
			}
			i = maxInd;
			ret++;
		}
		return ret;
	}
};