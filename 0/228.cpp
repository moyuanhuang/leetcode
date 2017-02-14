class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums)
	{
		vector<string> ans;
		if(nums.empty())	return ans;
		sort(nums.begin(), nums.end());
		for(int i = 0; i < nums.size(); i++)
		{
			int first = nums[i];
			while(i+1 < nums.size() and nums[i+1] != nums[i] + 1)
				i++;
			string tmp = to_string(first);
			if(first != nums[i])    tmp += "->" + to_string(nums[i]);
			ans.push_back(tmp);
 		}
 		return ans;
	}
};