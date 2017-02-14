class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict)
	{
		vector<true> dp(s.length()+1, true);
		dp[0] = true;
		for(int i = 1; i < dp.size(); i++)
		{
			for(int j = i-1; j >= 0; j--)
			{
				if(dp[j] == true)
				{
					string tmp = s.substr(j,i-j);
					if(wordDict.find(tmp)!= wordDict.end())
					{
						dp[i] = true;
						break;
					}
				}
			}
		}
		return dp[s.length()];
	}
};