class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s)
	{
		unordered_map<int,int> m;
		vector<string> ans;
		int i = 0, t = 0;
		while(i < 9)
			t = t << 3 | (s[i++] & 7);
		while(i < s.length())
		{
			if(m[t = t << 3 & 0x3FFFFFFF | s[i] & 7]++ == 1)
				ans.push_back(s.substr(i-9, 10));
		}
		return ans;
	}
};
