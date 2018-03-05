// leetcode 322. Coin Change
// medium
// dp[amount] = dp[amount - coin_val] + 1 for coin_val in coins

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for(int i = 0; i < dp.size(); i++){
            for(int c : coins){
                if(i - c >= 0 and dp[i-c] != -1){
                    int temp = dp[i-c] + 1;
                    if(dp[i] == -1){
                        dp[i] = temp;
                    }
                    else {
                        dp[i] = min(dp[i], temp);
                    }
                }
            }
        }
        return dp[amount];
    }
};
