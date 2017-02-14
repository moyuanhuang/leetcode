/* 49. Group Anagrams
 * Created by Moyuan Huang on Sep.22, 2016. 
*/
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		unordered_map<string, vector<string>> map;
		for(int i = 0; i < strs.size(); i++)
		{
			string temp(26,0);
			for(int j = 0; j < strs[i].length(); j++)
				temp[strs[i][j] - 'a']++;
			if(map.count(temp))
				map[temp].push_back(strs[i]);
			else
			{
				vector<string> group;
				group.push_back(strs[i]);
				map[temp] = group;
			}
		}
		vector<vector<string>> ret;
		for(unordered_map<string, vector<string>>::iterator i = map.begin(); i != map.end(); i++)
			ret.push_back(i->second);
		return ret;
	}
};