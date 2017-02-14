class Solution {
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> ans;
		if(numRows == 0)	return ans;
		vector<int> pre(1,1);
		ans.push_back(pre);
		if(numRows == 1)	return ans;
		for(int i = 1; i < numRows; i++)
		{
			vector<int> cur(i+1, 1);
			for(int j = 1; j< cur.size()-1; j++)
				cur[j] = pre[j-1] + pre[j];
			ans.push_back(cur);
			pre = cur;
		}
		return ans;
	}
};