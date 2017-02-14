class Solution {
public:
	string simplifyPath(string path)
	{
		string ret = "";
		vector<string> paths;
		int prev = -1, pos = 0;
		string temp = "";
		for(int i = 0; i < path.length(); i++)
		{
			if(path[i] == '/')
			{
				if(temp == "..")
					paths.pop_back(); 
				else if(temp == '.')
				{
					temp = "";
					continue;
				}
				else
					paths.push_back(temp);
				temp = "";
			}
			else
				temp.push_back(path[i]);
		}
		for(int i = 0; i < paths.size(); i++)
		{
			cout << '/' << paths[i];
			ret += paths[i];
		}
		return ret;
	}
};