// leetcode 188. Best Time to Buy and Sell Stock IV
// 2-dimensional dp, global and local

class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    int days = prices.size();
    if(days < 2)  return 0;
    if(k >= days/2)   return quickSolve(prices);

    vector<int> local(k + 1, 0), global(k+1, 0);
    for(int i = 1; i < days; i++){
      int diff = prices[i] - prices[i-1];
      int buffer = 0;
      for(int j = 1; j <= k; j++){
        local[j] = max(buffer + max(diff, 0), local[j] + diff);
        buffer = global[j];
        global[j] = max(global[j], local[j]);
      }
    }
    return global[k];
  }
  // int maxProfit(int k, vector<int>& prices) {
  //   int days = prices.size();
  //   if(days < 2)  return 0;
  //   if(k >= days/2)   return quickSolve(prices);
  //   // prices.insert(prices.begin(), 0);
  //   vector<vector<int> > global(days, vector<int>(k + 1, 0));
  //   vector<vector<int> > local(days, vector<int>(k + 1, 0));
  //
  //   for(int i = 1; i < days; ++i){
  //     int diff = prices[i] - prices[i-1];
  //     for(int j = 1;j <= k; ++j){
  //       local[i][j] = max(global[i-1][j-1] + max(diff, 0), local[i-1][j] + diff);
  //       global[i][j] = max(global[i-1][j], local[i][j]);
  //     }
  //   }
  //   return global[days-1][k];
  // }

private:
  int quickSolve(vector<int>& prices){
      cout << "quickSolve" << endl;
    int profit = 0;
    for(int i = 1; i < prices.size(); i++){
      profit += max(prices[i] - prices[i-1], 0);
    }
    return profit;
  }

};
