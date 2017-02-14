class Solution {
public:
	int titleToNumber(string s)
	{
		int ans = 0;
		for(int i = 0; i <s.length(); i++)
		{
			int tmp = s[i] - 'A' + 1;
			cout << tmp << endl;
			ans = ans* 26 + tmp; 
		}
		return ans;

	}
};
