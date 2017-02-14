class Solution {
public:
	bool isIsomorphic(string s, string t)
	{
		unordered_map<char, char> m;
		unordered_map<char, bool> used;
		if(s.length() != t.length())	return false;
		for(int i = 0; i < s.length(); i++)
		{
			char tmp = s[i];
			cout << tmp << " ";
			if(m.count(tmp) == 0)
			{
				m[tmp] = t[i];
				if(used.count(t[i]) != 0)
				    return false;
				else    used[t[i]] = true;
				continue;
			}
			else
			{
				if(t[i] != m[tmp])	return false;
			}
		}
		return true;
	}
};