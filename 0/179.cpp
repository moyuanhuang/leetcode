class Solution {
public:
	bool cmp(string& s1,, string& s2)
	{
		return s1+s2> s2+s1;
	}

	string largestNumber(vector<int>& nums)
	{
		vector<string> arr;
		for(auto i:nums)
			arr.push_back(to_string(i));
		sort(arr.begin(), arr.end(), cmp());
		string ans("");
		for(auto i: arr)
			ans += i;
		while(ans[0] == '0' and ans.length()>1)
			ans.erase(0,1);
		return ans;
	}
};