//2021/7/3
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int p = s1.length(), q = s2.length(), r = s3.length();
        vector<vector<bool>> dp(p + 1, vector<bool>(q + 1, false));
    /*
        For convenience, assumes that index start from 1
        dp[i][j] := whether s3[1:i+j] is interleaving of s1[1:i] & s2[1:j] or not

          -- true, if (s3[i+j] == s1[i] && dp[i-1][j]) || (s3[i+j] == s2[j] && dp[i][j-1])
        = |
          -- false, otherwise
    */
        if (p + q != r) {
            return false;
        }
        
        //B.C.
        for (int i = 0; i <= p; ++i) {
            dp[i][0] = (s1.substr(0, i) == s3.substr(0, i));
        }
        for (int j = 0; j <= q; ++j) {
            dp[0][j] = (s2.substr(0, j) == s3.substr(0, j));
        }
        
        for (int i = 1; i <= p; ++i) {
            for (int j = 1; j <= q; ++j) {
                if (s3[i+j-1] == s1[i-1] && dp[i-1][j]) {
                    dp[i][j] = true;
                    continue;
                }
                if (s3[i+j-1] == s2[j-1] && dp[i][j-1]) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[p][q];
    }
};