class Solution {
public:
	string getPermutation(int n, int k)
	{
		vector<int> factorial(n + 1, 1);
		vector<int> nums{1,2,3,4,5,6,7,8,9};
		string ret = "";

		for(int i = 1; i < factorial.size(); i++)
			factorial[i] = factorial[i-1] * i;

		for(int i = 0; i < n; i++)
		{
			int per_group = factorial(n-i-1);
			ret += to_string(nums[k/ (per_group)]);
			k = k%per_group;
			nums.erase(nums.begin() + k/per_group);
		}
		return ret;
	}
};