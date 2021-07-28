//2021/7/27
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        enum dir {up, right, down, left};
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(4, 0)));
        vector<vector<bool>> ones(n, vector<bool>(n, true));
        int ans = 0;
        for (const auto &mine : mines) {
            ones[mine[0]][mine[1]] = false;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (ones[i][j]) {
                    dp[i][j][left] = (j>=1)? dp[i][j-1][left] + 1 : 1;
                    dp[i][j][up] = (i>=1)? dp[i-1][j][up] + 1 : 1;
                }
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (ones[i][j]) {
                    dp[i][j][right] = (j<n-1)? dp[i][j+1][right] + 1 : 1;
                    dp[i][j][down] = (i<n-1)? dp[i+1][j][down] + 1 : 1;
                }
                ans = max(ans, min({dp[i][j][up], dp[i][j][down], dp[i][j][left], dp[i][j][right]}));
            }
        }
        return ans;
    }
};