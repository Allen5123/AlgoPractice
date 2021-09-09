//2021/8/13
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length(), n = str2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)), table(m + 1, vector<int>(n + 1, -1));
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    table[i][j] = 0;
                }
                else {
                    if (dp[i][j-1] > dp[i-1][j]) {
                        dp[i][j] = dp[i][j-1];
                        table[i][j] = 2;
                    }
                    else {
                        dp[i][j] = dp[i-1][j];
                        table[i][j] = 1;
                    }
                }
            }
        }
        
        string ans;
        while (m > 0 && n > 0) {
            char toadd;
            if (table[m][n] == 0) {
                toadd = str1[m-1];
                --m;
                --n;
            }
            else if (table[m][n] == 1) {
                toadd = str1[m-1];
                --m;
            }
            else {
                toadd = str2[n-1];
                --n;
            }
            ans.insert(ans.begin(), toadd);
        }
        
        if (m > 0) {
            ans.insert(0, str1, 0, m);
        }
        else if (n > 0) {
            ans.insert(0, str2, 0, n);
        }
        else {}
        
        return ans;
    }
};