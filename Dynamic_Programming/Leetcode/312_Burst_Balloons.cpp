//2021/7/10
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        //dp[i][j] := maximum coin after brusted all baloons between [i:j]
        if (n == 1) {
            return nums[0];
        }
        dp[0][0] = nums[0] * nums[1];
        dp[n-1][n-1] = nums[n-2] * nums[n-1];
        for (int i = 1; i < n - 1; ++i) {
            dp[i][i] = nums[i-1] * nums[i] * nums[i+1];
        }
        for (int l = 2; l <= n; ++l) {
            for (int i = 0; i + l - 1 < n; ++i) {
                int j = i + l - 1;
                int left = (i == 0)? 1 : nums[i-1];
                int right = (j == n-1)? 1 : nums[j+1];
                //position k is the "last" bursted ballon in range[i:j]
                for (int k = i; k <= j; ++k) {
                    int reward = left * nums[k] * right;
                    if (k == i) {
                        dp[i][j] = max(dp[i][j], reward + dp[k+1][j]);
                    }
                    else if (k == j){
                        dp[i][j] = max(dp[i][j], reward + dp[i][k-1]);
                    }
                    else {
                        dp[i][j] = max(dp[i][j], reward + dp[i][k-1] + dp[k+1][j]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};