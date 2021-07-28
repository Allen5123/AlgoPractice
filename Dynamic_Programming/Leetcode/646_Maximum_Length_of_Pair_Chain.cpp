//2021/7/24
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b){
            return (a[1] < b[1]);
        }); //sorted by right
        int n = pairs.size(), ans = 0;
        vector<int> dp(n, 0); //dp[i] := longest chain end with i
        ans = dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            int best = 1;
            for (int j = 0; j < i; ++j) {
                if (pairs[j][1] < pairs[i][0]) {
                    best = max(best, dp[j] + 1);
                }
                else {
                    break;
                }
            }
            dp[i] = best;
            ans = max(ans, best);
        }
        return ans;
    }
};