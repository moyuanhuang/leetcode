/*
 * 14. Longest Common Prefix
 * Created by Moyuan Huang on 8/26/2016
*/
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		string result = "";
		int maxLen = 0;
		for(int i = 0; i < strs.size(); i++)
		{
			maxLen = strs[i].size() > maxLen? strs[i].size(): maxLen;
			if(maxLen == 0)	return "";
		}
		for(int i = 0; i < maxLen; i++)
		{
			result += strs[0][i];
			for(int j = 1; j < strs.size(); j++)
			{
				if( strs[j][i] != strs[0][i] )
				{
					result.erase(result.length()-1);
					return result;
				}
			}
		}
		return result;
    }
};