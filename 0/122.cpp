class Solution {
public:
	int maxProfit(vector<int>& prices)
	{
		int profit;
		for(int i = 1; i < prices.size(); i++)
			profit += (prices[i] - prices[i-1]) > 0? (prices[i] - prices[i-1]): 0;
		return profit;
	}
};