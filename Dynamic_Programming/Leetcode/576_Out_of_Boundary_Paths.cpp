//2021/7/22
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        //dp[k][i][j] := number of path to go out of boundary, using k moves at (i, j)
        
        for (int k = 1; k <= maxMove; ++k) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    int res = 0;
                    for (auto dir : dirs) {
                        int nrow = i + dir[0], ncol = j + dir[1];
                        bool outOfBound_ = false;
                        if (nrow < 0 || nrow >= m) {
                            res = (res + 1) % MOD;
                            outOfBound_ = true;
                        }
                        if (ncol < 0 || ncol >= n) {
                            res = (res + 1) % MOD;
                            outOfBound_ = true;
                        }
                        if (!outOfBound_) {
                            res = (res + dp[k-1][nrow][ncol]) % MOD;
                        }
                    }
                    dp[k][i][j] = res;
                }
            }
        }
        return dp[maxMove][startRow][startColumn];
    }
private:
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}, MOD = 1.e9 + 7;
};