class Solution {
private:
	void dfs(int n, int k, int height, vector<vector<int>>& ret, vector<int> cur)
	{
		if(cur.size() == k)
		{
			ret.push_back(cur);	
			return;
		}
		for(int i = height; i <= n; i++)
		{
			cur.push_back(i);
			dfs(n, k, i+1, ret, cur);
			cur.pop_back();
		}
	}
public:
	vector<vector<int>> combine(int n, int k)
	{
		vector<vector<int>> ret;
		vector<int> cur;
		dfs(n, k, 1, ret, cur);
		return ret;
	}
};
	/*
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		int i = 0;
		vector<int> p(k, 0);
		while (i >= 0) {
			p[i]++;
			if (p[i] > n) --i;
			else if (i == k - 1) result.push_back(p);
			else {
			    ++i;
			    p[i] = p[i - 1];
			}
		}
		return result;
	}
	*/
};