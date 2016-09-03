#include <iostream>
#include <vector>

class Solution
{
public:
	Solution()
	{
		std::cout << "initiating Solution..." << std::endl;
	};
	// This is where you define the solution function
	std::vector<std::vector<int> > threeSum(std::vector<int>& nums);
};
