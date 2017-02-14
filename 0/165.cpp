class Solution {
public:
	int compareVersion(string version1, string version2)
	{
		stringstream s1(version1), s2(version2);
		string tmp1, tmp2;
		while(true)
		{
		    if(!getline(s1, tmp1, '.')) tmp1 = "0";
		    if(!getline(s2, tmp2, '.')) tmp2 = "0";
		    if(not s1 and not s2)   return 0;
			if(stoi(tmp1) > stoi(tmp2))	return 1;
			if(stoi(tmp1) < stoi(tmp2)) return -1;
			
		}
		return 0;
	}
};