/* 40. Combination Sum II
 * Created by Moyuan Huang on Sep.22, 2016.
*/
class Solution {
private:
	void calculate(vector<vector<int>>& ret, vector<int>& candidates, int index, int target, vector<int>& cur)
	{
		if(index >= candidates.size())	return;
		if(target == 0)
		{
			ret.push_back(cur);
			return;
		}
		if(candidates[index] > target)	return;
		if(candidates[index] <= target)
		{
			for(int i = index+1; i < candidates.size(); i++)
			{
				cur.push_back(candidates[i]);
				calculate(ret, candidates, i, target-candidates[i], cur);
				cur.pop_back();
			}
		}
		return;
	}
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> ret;
		vector<int> cur;
		for(int i = 0; i < candidates.size(); i++)
			calculate(ret, candidates, 0, target, cur);
		return ret;
	}
};