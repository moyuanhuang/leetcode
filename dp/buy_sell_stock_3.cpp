class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[2][4] = {INT_MIN, 0, INT_MIN, 0};  // sometime using array is easier than vector
        int cur = 0, next = 1;
        for(int i = 0; i < prices.size(); i++){
            dp[next][0] = max(dp[cur][0], -prices[i]);
            dp[next][1] = max(dp[cur][1], dp[cur][0] + prices[i]);
            dp[next][2] = max(dp[cur][2], dp[cur][1] - prices[i]);
            dp[next][3] = max(dp[cur][3], dp[cur][2] + prices[i]);
            swap(cur, next); // a tricky strategy for swaping cur and next
        }
        return max(dp[cur][1], dp[cur][3]);

    }
};
