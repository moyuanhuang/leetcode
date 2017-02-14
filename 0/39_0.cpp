/* 40. Combination Sum II
 * Created by Moyuan Huang on Sep.22, 2016.
*/
class Solution {
private:
	void calculate(vector<vector<int>>& ret, vector<int>& candidates, int index, int target, vector<int>& cur)
	{
		if(target == 0)
		{
			ret.push_back(cur);
			return;
		}
		if(index >= candidates.size() and candidates[index] > target)	return;
		if(candidates[index] <= target)
		{
			for(int i = index; i < candidates.size(); i++)
			{
				cur.push_back(candidates[i]);
				calculate(ret, candidates, i+1, target-candidates[i], cur);
				cur.pop_back();
				while(i < candidates.size() - 1 and candidates[i] == candidates[i+1])   i++;
			}
		}
		return;
	}
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
		sort(candidates.begin(), candidates.end());
		for(int i = 0; i < candidates.size(); i++)  cout << candidates[i] << ' ';
		cout << endl;
		vector<vector<int>> ret;
		vector<int> cur;
		calculate(ret, candidates, 0, target, cur);
		return ret;
	}
};