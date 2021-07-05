//2021/6/29
class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        int dp1[100][100]; //# common substring in s[0:i]&t[0:j]
        int dp2[100][100]; //# Substrings That Differ by One Character in s[0:i]&t[0:j]
        fill_n(&dp1[0][0], sizeof(dp1)/sizeof(int), 0);
        fill_n(&dp2[0][0], sizeof(dp2)/sizeof(int), 0);
        for (int i = 0; i < s.length(); ++i) {
            for (int j = 0; j < t.length(); ++j) {
                if (i == 0 || j == 0) {
                    dp1[i][j] = (s[i] == t[j])? 1 : 0;
                    dp2[i][j] = (s[i] != t[j])? 1 : 0;
                }
                else if (s[i] == t[j]) {
                    dp1[i][j] = dp1[i-1][j-1] + 1;
                    dp2[i][j] = dp2[i-1][j-1];
                }
                else {
                    dp1[i][j] = 0;
                    dp2[i][j] = dp1[i-1][j-1] + 1;
                }
                ans+=dp2[i][j];
            }
        }
        return ans;
    }
};