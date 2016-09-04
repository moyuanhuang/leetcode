/*
 * 13. Roman to Integer
 * Created by Moyuan Huang on 8/26/2016
*/
 class Solution {
public:
	int romanToInt(string s)
	{
		map<char, int> dict;
		dict['M'] = 1000;
		dict['D'] = 500;
		dict['C'] = 100;
		dict['L'] = 50;
		dict['X'] = 10;
		dict['V'] = 5;
		dict['I'] = 1;
		int result = 0;
		for(int i = 0; i < s.length() - 1; i++)
		{
			if( dict[s[i]] < dict[s[i+1]])	result -= dict[s[i]];
			else	result += dict[s[i]];
		}
		result += dict[s[s.length()-1]];
		return result;
    }
};
