//2021/8/8
class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, INT_MAX));
        //dp[i][j] := minimum waste considering nums[0:i] at most j resizing
        
        //B.C.
        for (int i = 0, mx = 0, s = 0; i < n; ++i) {
            s+=nums[i];
            mx = max(mx, nums[i]);
            dp[i][0] = mx * (i + 1) - s;
        }
        
        for (int j = 1; j <= k; ++j) {
            dp[0][j] = 0;
            for (int i = 1; i < n; ++i) {
                for (int m = i, mx = 0, s = 0; m >= 0; --m) {
                    s+=nums[m];
                    mx = max(mx, nums[m]);
                    dp[i][j] = min(dp[i][j], mx * (i - m + 1) - s + ((m > 0)? dp[m-1][j-1] : 0));
                }
            }
        }
        
        return dp[n-1][k];
    }
};