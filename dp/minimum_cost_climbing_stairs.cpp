// 746. Min Cost Climbing Stairs
// easy
// simple dp

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        vector<int> dp(cost.size() + 1, 0);
        for(int i = 2; i < dp.size(); i++){
            dp[i] = min(dp[i - 2] + cost[i-2], dp[i - 1] + cost[i-1]);
        }
        return dp[cost.size()];
    }
};
