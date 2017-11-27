// leetcode 312. Bursting balloons
// This is a typical 2-dimensional dp problem
// dp[i][j] is the BEST score we can get from nums[i] to nums[j]
// dp[i][j] = max(nums[LEFT - 1]*nums[k]*nums[RIGHT + 1] + dp[i][k - 1] + dp[k + 1][j])

class Solution {
public:
  int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);

    vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), 0));
    for(int len = 1; len <= n; len++){
      for(int left = 1; left <= n - len + 1; left++){
        int right = left + len - 1;
        for(int k = left; k <= right; ++k){
          dp[left][right] = max(dp[left][right], dp[left][k-1] + dp[k+1][right] + nums[left-1] * nums[k] * nums[right + 1]);
        }
      }
    }
    return dp[1][n];
  }
};
