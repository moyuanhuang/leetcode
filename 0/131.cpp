class Solution {
public:
	vector<vector<string>> partition(string s)
	{
		vector<vector<string>> ans;
		vector<string> cur;
		helper(s, ans, cur, 0);
		return ans;
	}

	void helper(string& s, vector<vector<string>>& ans, vector<string>& cur, int idx)
	{
		if(idx == s.length())
		{
			ans.push_back(cur);
			return;
		}
		for(int i = 0; idx + i < s.length(); i++)
		{
			string tmp = s.substr(idx, i);
			if(isPal(tmp))
			{
				cur.push_back(tmp);
				helper(s, ans, cur, idx + 1 + i);
				cur.pop_back();
			}
		}
		return;
	}

	bool isPal(string s)
	{
		int b = 0, e = s.length()-1;
		while(b <= e)
			if(s[b++] != s[e--])	return false;
		return true;
	}
};