class Solution {
public:
	bool isPalindrome(string s)
	{
		if(s.empty())	return true;
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		int a = -1, b = s.size();
		while(a <= b)
		{
			while(isalnum(s[++a]));
			while(isalnum(s[--b]));
			if(a > b)	return true;
			if(s[a] != s[b])	return false;
		}
		return true;
	}
};