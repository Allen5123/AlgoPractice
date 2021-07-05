//2021/7/7
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0); //maximun sum of patrition array in arr[1:i]
        for (int i = 1; i <= n; ++i) {
            int maxElement = 0, best = 0;
            for (int j = 0; j < k && i - j > 0; ++j) {
                maxElement = max(maxElement, arr[i-1-j]);
                best = max(best, dp[i-j-1] + maxElement*(j+1));
            }
            dp[i] = best;
        }
        return dp[n];
    }
};