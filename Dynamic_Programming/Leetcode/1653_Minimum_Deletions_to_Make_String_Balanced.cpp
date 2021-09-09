//2021/9/3
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        //dp[i] := minimum deletion to make s[1:i] balanced, index start from 1
        for (int i = 1, countb = 0; i <= n; ++i) {
            if (s[i-1] == 'b') { // no problem
                ++countb;
                dp[i] = dp[i-1];
            }
            else { //delete 'a' or delete all of 'b' before it
                dp[i] = min(1 + dp[i-1], countb);
            }
        }
        return dp[n];
    }
};