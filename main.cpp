#include "Solution.h"
#include <vector>

using namespace std;
int main()
{
	Solution sol = Solution();
	vector<int> nums;
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-4);
	int res = sol.threeSumClosest(nums, 1);
	cout << res << endl;
	return 0;
}