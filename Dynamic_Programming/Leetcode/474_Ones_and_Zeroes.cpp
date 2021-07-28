//2021/7/19
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        vector<vector<vector<int>>> dp(s, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        //dp[i][j][k] := maximum subset at most m's zeros & n's ones, when considering strs[0:i]
        
        unordered_map<int, int> zeros;
        for (int i = 0; i < s; ++i) {
            int counts = count(strs[i].begin(), strs[i].end(), '0');
            zeros.insert(make_pair(i, counts));
        }
        
        //B.C.
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (zeros[0] <= i && strs[0].length()-zeros[0] <= j) {
                    dp[0][i][j] = 1;
                }
            }
        }
        
        for (int i = 1; i < s; ++i) {
            int zero = zeros[i], one = strs[i].length() - zero;
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    if (zero <= j && one <= k) {
                        dp[i][j][k] = max(1 + dp[i-1][j-zero][k-one], dp[i-1][j][k]);
                    }
                    else {
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            }
        }

        return dp[s-1][m][n];
    }
};