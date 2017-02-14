class Solution {
public:
	int countDigitOne(int n)
	{
		int ans;
		for(int i = 1; i <= n; i++)
		{
			int tmp = i;
			while(tmp > 0)
			{
				ans += (tmp % 10 == 1)? 1: 0;
				tmp /= 10;
			}
		}
		return ans;
	}
};