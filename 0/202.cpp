class Solution {
public:
	bool isHappy(int n)
	{
		unordered_map<int,bool>	m;
		while(n != 1)
		{
			int tmp = 0;
			while(n != 0)
			{
				tmp += (n & 1) * (n & 1);
				n >>= 1;
			}
			if(m[tmp] == true)	return false;
			else	m[tmp] = true;
			n = tmp;
		}
		return true;

	}
};