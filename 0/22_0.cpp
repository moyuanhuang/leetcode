/* 22. Generate Parentheses
 * Created by Moyuan Huang on Sep.4, 2016.
*/
class Solution {
private:
	void search(int left, int right, string s, vector<string>& v)
	{
		if(!left and !right)
		{
			v.push_back(s);
			return;
		}
		else if(left > 0)	search(left-1, right, s+"(", v);
		else if(left > right)	search(left, right-1, s+")", v);
		return;
	}
public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> v;
		search(n,n,"",v);
		return v;
	}
};