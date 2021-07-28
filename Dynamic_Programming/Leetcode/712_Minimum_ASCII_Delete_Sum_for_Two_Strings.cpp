//2021/7/25
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        //dp[i][j] := ans when considering s1[1:i] and s2[1:j], index start from 1
        
        //B.C.
        for (int i = 1; i <= n; ++i) {
            dp[0][i] = dp[0][i-1] + (s2[i-1] - '\0');
        }
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = dp[i-1][0] + (s1[i-1] - '\0');
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = min((s1[i-1]-'\0') + dp[i-1][j], (s2[j-1]-'\0') + dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};