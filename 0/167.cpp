class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target)
	{
		int i = 0, j = numbers.size()-1;
		while(true)
		{
			if(numbers[i] + numbers[j] > target)	--j;
			else if(numbers[i] + numbers[j] < target)	++i;
			else	return	{++i, ++j};
		}
	}
};