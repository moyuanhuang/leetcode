class Solution {
public:
	int minDistance(string word1, string word2) {
		if(word1.empty())	return word2.length();
		if(word2.empty())	return word1.length();
		vector<vector<int> > dp(word1.length()+1, vector<int>(word2.length()+1, 0));
		for(int i = 1; i < dp.size(); ++i)
		    dp[i][0] = i;
		for(int i = 1; i < dp[0].size(); ++i)
		    dp[0][i] = i;
// 		cout << word1.length() << " " << word2.length() << endl;
// 		cout << dp.size() << " " << dp[0].size() << endl;
		for(int j = 1; j <= word2.length(); ++j){
			for(int i = 1; i <= word1.length(); ++i){
			 //   cout << i << " " << j << endl;
				int insert = dp[i][j - 1] + 1;
				int del = dp[i - 1][j] + 1;
				int repl;
				if(word1[i-1] == word2[j-1])
					repl = dp[i-1][j-1];
				else
					repl = dp[i-1][j-1] + 1;
				// cout << insert << del << repl << endl;
				dp[i][j] = min(repl, min(del, insert));
				// cout << dp[i][j] << endl;
			}
		}
		return dp[word1.length()][word2.length()];
	}
};