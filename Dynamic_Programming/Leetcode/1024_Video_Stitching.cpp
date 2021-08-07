//2021/8/5
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end(), [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
        int n = clips.size(), MAXSEG = 1000;
        vector<vector<int>> dp(n, vector<int>(time + 1, MAXSEG));
        
        dp[0][0] = 0;
        if (clips[0][0] == 0) {
            for (int i = clips[0][0] + 1; i <= clips[0][1] && i <= time; ++i) {
                dp[0][i] = 1;
            }
        }
        
        for (int j = 0; j <= time; ++j) {
            for (int i = 1; i < n; ++i) {
                if (j >= clips[i][0] && j <= clips[i][1]) {
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i-1][clips[i][0]]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }       
        }
        
        return (dp[n-1][time] < MAXSEG)? dp[n-1][time] : -1;
    }
};