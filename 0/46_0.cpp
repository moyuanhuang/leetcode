/* 46. Permutations
 * Created by Moyuan Huang on Sep.22, 2016. 
*/
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums)
	{
		vector<vector<int>> ret;
		ret.push_back(nums);
		ret.push_back(nums);
		for(int i = 0; i < nums.size(); i++)
		{
			int size = ret.size();
			for(int j = 0; j < ret.size(); j++)
			{
				for(int k = i + 1; k < nums.size(); k++)
				{
					vector<int> temp = ret[j];
					swap(temp[i], temp[k]);
					ret.push_back(temp);
				}
			}
		}
		return ret;
	}
};