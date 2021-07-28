//2021/7/28
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<int>> dp(n, vector<int>(k + 1, INT_MAX));
        //dp[i][j] := cheapest price to i, at most j stop
        
        //B.C.
        for (const auto &flight : flights) {
            if (flight[0] == src) {
                dp[flight[1]][0] = flight[2];
            }
        }
        dp[src][0] = 0;
        
        for (int j = 1; j <= k; ++j) {
            for (int i = 0; i < n; ++i) {
                dp[i][j] = dp[i][j-1];
                for (const auto &flight : flights) {
                    if (flight[1] == i && dp[flight[0]][j-1] < INT_MAX) {
                        dp[i][j] = min(dp[i][j], dp[flight[0]][j-1] + flight[2]);
                    }
                }
            }
        }
        
        return (dp[dst][k] < INT_MAX)? dp[dst][k] : -1;
    }
};