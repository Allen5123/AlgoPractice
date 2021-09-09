//2021/8/16
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<int>> dp1(m, vector<int>(n, 0)); //maximum continuous 1, moving leftward
        vector<vector<int>> dp2(m, vector<int>(n, 0)); //maximum continuous 1, moving upward
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dp1[i][j] = j - 1 >= 0 ? dp1[i][j-1] + 1 : 1;
                    dp2[i][j] = i - 1 >= 0 ? dp2[i-1][j] + 1 : 1;
                    for (int w = min(dp1[i][j], dp2[i][j]); w >= 1; --w) {
                        if (i - w + 1 >= 0 && j - w + 1 >= 0 && dp1[i-w+1][j] >= w && dp2[i][j-w+1] >= w) {
                            ans = max(ans, w * w);
                            break;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};