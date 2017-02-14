class Solution {
public:
	string convertToTitle(int n)
	{
		string ans("");
		while(n > 0)
		{
			stringstream ss;
			ss << (char('A' + ((--n) % 26)));
			ans = ss.str() + ans;
			cout << ans << endl;
			n /= 26;
		}
		return ans;
	}
};