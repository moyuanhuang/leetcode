class Solution {
public:
	bool isPowerOfTwo(int n)
	{
		while(n != 1)
		{
			if(n & 0x0001)
				return false;
			n >>= 1;
		}
		return true;
	}
};