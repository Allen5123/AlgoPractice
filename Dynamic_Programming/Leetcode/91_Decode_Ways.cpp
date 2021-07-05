//2021/7/2
class Solution {
public:
    int numDecodings(string s) {
        int dp[100] = {0};
        if (s == "") {
            return 0;
        }
        dp[0] = (s[0] == '0')? 0 : 1;
        dp[1] = (s[1] == '0')? 0 : dp[0];
        int temp = stoi(s.substr(0, 2));
        if (temp >= 10 && temp <= 26) {
            dp[1]+=1;
        }
        for (int i = 2; i < s.length(); ++i) {
            dp[i] = (s[i] == '0')? 0 : dp[i-1];
            int temp = stoi(s.substr(i - 1, 2));
            if (temp >= 10 && temp <= 26) {
                dp[i]+=dp[i-2];
            }
        }
        return dp[s.length()-1];
    }
};