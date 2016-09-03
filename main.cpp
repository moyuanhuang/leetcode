#include "Solution.h"
#include <vector>

using namespace std;
int main()
{
	Solution sol = Solution();
	vector<int> nums;
	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(1);
	vector<vector<int> > res = sol.threeSum(nums);
	for(int i =0; i < res.size();i++)
	{
		for(int j = 0; j < res[i].size(); j++)
			cout << res[i][j];
		cout << endl;
	}
	return 0;
}