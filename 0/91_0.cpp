class Solution {
public:
	int numDecodings(string s)
	{
		if(s.empty())	return 0;

		int len = s.size();
		vector<int> comb(len+1, 1);
		for(int i = 2; i < comb.size(); i++)
		{
			int one = s[i] - '0';
			int two = stoi(s.substr(i-1,2));
			comb[i] = comb[i-1];
			if(two >= 10 and two <= 26)
				comb[i] += comb[i-2];
		}
		return comb[len];
	}
};