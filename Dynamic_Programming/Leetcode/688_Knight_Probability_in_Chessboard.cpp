//2021/7/21
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n, 0.)));
        //dp[k][i][j] := probability that the knight remains on the board after k moves, started at (i,j)
        
        //B.C.
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[0][i][j] = 1.;
            }
        }
        
        for (int move = 1; move <= k; ++move) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    double prob = 0.;
                    for (const auto &dir : dirs) {
                        int nrow = i + dir[0], ncol = j + dir[1];
                        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n) {
                            prob+=(1./8.)*dp[move-1][nrow][ncol];
                        }
                    }
                    dp[move][i][j] = prob;
                }
            }
        }
        
        return dp[k][row][column];
    }
private:
    int dirs[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
};