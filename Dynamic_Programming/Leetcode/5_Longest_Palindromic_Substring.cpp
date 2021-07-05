//2021/6/27
class Solution {
public:
    string longestPalindrome(string s) {
        bool dp[1000][1000];  //substring s[i:j] is Palindrome or not
        int start = 0, len = 1;
        fill_n(dp, sizeof(dp)/sizeof(bool), false);
        if (s == "") {
            return s;
        }
        for (int k = 1; k <= s.length(); ++k) {
            for (int i = 0; i + k - 1 < s.length(); ++i) {
                int j = i + k - 1;
                if (k == 1) { //length = 1
                    dp[i][j] = true;
                }
                else if (k == 2) { //length = 2
                    if (s[i] == s[j]) {
                        start = i;
                        len = k;
                        dp[i][j] = true;
                    }
                }
                //length >= 3
                else if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    if (len < k) {
                        start = i;
                        len = k;
                    }
                }
                else {}
            }
        }
        return s.substr(start, len);
    }
};