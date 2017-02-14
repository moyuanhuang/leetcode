/* 28.Implement strStr()
 * Created by Moyuan Huang on Sep.15th, 2016.
*/
class Solution {
public:
	int strStr(string haystack, string xneedle)
	{
	    if(xneedle == "")   return 0;
		int sLen = haystack.length();
		int nLen = xneedle.length();
		if(sLen < nLen)	return -1;
		for(int i = 0; i < sLen - nLen + 1; i++)
		{
			string sub = haystack.substr(i, nLen);
			if(sub == xneedle)
				return i;
		}
		return -1;
	}
};