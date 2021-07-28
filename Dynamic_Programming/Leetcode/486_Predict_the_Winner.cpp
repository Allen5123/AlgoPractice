//2021/7/20
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(n, 0));
        //dp[i][j] := maximum scores that player can get between nums[i:j]
        
        //B.C.
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }
        
        for (int l = 2; l <= n; ++l) {
            for (int i = 0; i + l - 1 < n; ++i) {
                int j = i + l - 1;
                int left = nums[i] + accumulate(nums.begin() + i + 1, nums.begin() + j + 1, 0) - dp[i+1][j];//player chooses left can get : nums[i] + ( sum of nums[i+1][j] - maximum scores that opponent can get{i.e. dp[i+1][j]} )
                int right = nums[j] + accumulate(nums.begin() + i, nums.begin() + j , 0) - dp[i][j-1];//player chooses right can get : nums[j] + ( sum of nums[i][j-1] - maximum scores that opponent can get between nums[i][j-1]{i.e. dp[i][j-1]} )
                dp[i][j] = max(left, right);
            }
        }
        
        return (dp[0][n-1] >= sum-dp[0][n-1]);
    }
};