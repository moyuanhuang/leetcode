class Solution {
public:
	int maxProfit(vector<int>& prices)
	{
		int min = INT_MAX, max = 0;
		for(int i = 0; i < prices.size(); i++)
		{
			min = prices[i] > min? min:prices[i];
			max = (prices[i] - min) > max? (prices[i]-min):max;
		}
		return max;
	}
};