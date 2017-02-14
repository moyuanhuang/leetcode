class Solution {
public:
	int trailingZeroes(int n)
	{
		int ans = 0;
		int fact = 5;
		while(n > 0)
		{
			ans += n/ fact;
			fact *= 5;
		}
		return ans;
	}
};