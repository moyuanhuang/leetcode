class Solution {
public:
	int lengthOfLastWord(string s) {
		int index = s.find_last_of(' ');
		if (index == -1)	return 0;
		return str.substr(index+1).length();
	}
};