// leetcode 518. Coin Change 2
// this is almost a traditional knapsack problem
// use 2-d dp for the basic Solution, then it can be
// optimized to use 1-d dp
// dp[i][j] means how many combinations we can get if
// we use the first i coins to make j money

class Solution {
public:
    int change(int amount, vector<int>& coins) {
      vector<int> dp(amount+1, 0);
      dp[0] = 1;    // important!! handle both cases where amount:0, coins:[] and amount:7, coins:[]
      for(int coin : coins){
        dp[0] = 1;
        for(int i = coin; i < amount + 1; ++i){
          dp[i] += dp[i - coin];
        }
      }
      return dp[amount];
    }

  // 2-dimensional dp, can be optimized to use 1-d dp, see above
  // int change(int amount, vector<int>& coins) {
  //   vector<vector<int> > dp(coins.size()+1, vector<int>(amount+1, 0));
  //   dp[0][0] = 1;
  //   for(int i = 1; i < coins.size()+1; ++i){
  //     dp[i][0] = 1;
  //     for(int j = 1; j < amount+1; ++j){
  //       dp[i][j] = dp[i-1][j] + (j >= coins[i-1] ? dp[i][j-coins[i-1]] : 0);
  //     }
  //   }
  //   return dp[coins.size()][amount];
  // }
};
