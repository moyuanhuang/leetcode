class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n)
	{
		vector<vector<int>> ans;
		vector<int> cur;
		if(k > 9 or n > 45)	return ans;
		helper(n, k, ans, cur, 0);
		return ans;
	}
	
private:
	void helper(int sum, int k, vector<vector<int>>& ans, vector<int>& cur, int begin)
	{
		if(k == 0 and sum == 0)
		{
			ans.push_back(cur);
			return;
		}
		if(sum < 0 or k == 0)	return;
		for(int i = begin+1; i <= 9; i++)
		{
			cur.push_back(i);
			helper(sum - i, k - 1, ans, cur, i);
			cur.pop_back();
		}
		return;
	}
};