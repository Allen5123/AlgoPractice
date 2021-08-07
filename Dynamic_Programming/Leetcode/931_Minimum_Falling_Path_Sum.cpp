//2021/8/2
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        //dp[i][j] := minimum falling path sum to (i, j)
        
        for (int i = 0; i < n; ++i) {
            dp[0][i] = matrix[0][i];
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j > 0) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + matrix[i][j]);
                }
                if (j < n - 1) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j+1] + matrix[i][j]);
                }
                dp[i][j] = min(dp[i][j], dp[i-1][j] + matrix[i][j]);
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, dp[n-1][i]);
        }
        
        return ans;
    }
};