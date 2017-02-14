class Solution {
public:
	int hammingWeight(uint32_t n) {
		int ans = 0;
		int mask = 1;
		for(int i = 0; i < 32; i++)
		{
			if(mask & n)	ans++;
			mask = mask << 1;
		}
		return ans;
	}
};