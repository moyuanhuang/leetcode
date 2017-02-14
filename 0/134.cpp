class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
	{
		int ans = 0;
		for(int i = 0; i < gas.size(); i++)
			gas[i] -= cost[i];

		int n = gas.size();
		int sum = 0; 
		for(int i = 0; i < 2*n -1; i++)
		{
			sum += gas[i%n];
			if(sum < 0)
			{
				ans = i + 1;
				if(ans >= n)	return -1;
				sum = 0;
			}
		}
		return ans;
	}
};
