//2021/7/30
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<double>> dp(n, vector<double>(k + 1, 0));
        //dp[i][j] := ans of considering nums[0:i] at most j partition
        
        //B.C.
        double sum = 0.;
        for (int i = 0; i < n ; ++i) {
            sum+=(double)nums[i];
            dp[i][1] = (sum)/(double)(i+1);
        }
        
        for (int j = 2; j <= k; ++j) {
            for (int i = 0; i < n; ++i) {
                double sum = 0.;
                for (int m = i; m >= 0; --m) {
                    sum+=(double)nums[m];
                    dp[i][j] = max(dp[i][j], sum/(double)(i-m+1) + ((m > 0) ? dp[m-1][j-1] : 0));
                }
            }
        }
        
        return dp[n-1][k];
    }
};