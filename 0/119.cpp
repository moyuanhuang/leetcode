class Solution {
public:
	vector<int> getRow(int rowIndex)
	{
		vector<int> row(1,1);
		if(rowIndex == 1)	return row;
		for(int i = row.size(); i >= 1; i++)
		{
			row.push_back(1);
			row[i] += row[i-1];
		}
		return row;
	}
};