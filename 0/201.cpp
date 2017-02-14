class Solution {
public:
	int rangeBitwiseAnd(int m, int n)
	{
		// int mask = ~0;
		// while(mask != 0)
		// {
		// 	if((m&mask) == (n&mask))	break;
		// 	mask <<= 1;
		// }
		// return m & mask;
		return (n>m)?(rangeBitwiseAnd(m>>1, n>>1) << 1): m;
	}
};