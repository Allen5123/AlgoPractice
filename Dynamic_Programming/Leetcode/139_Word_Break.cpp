//2021/7/6
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n + 1, false);
        //assume index start from 1
        //dp[i] := whether there exsits substring t == s[j:i], for some 1 <= j <= i, i.e. suffix of s[*:i]
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < wordDict.size(); ++j) {
                int l = wordDict[j].length();
                if (i < l) {
                    continue;
                }
                int pos = s.substr(0, i).find(wordDict[j], i - l);
                if (pos != string::npos && dp[i-l]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};