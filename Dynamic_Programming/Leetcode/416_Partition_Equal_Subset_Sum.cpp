//2021/7/17
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        /*
            The question is equivalent with whether there exists some elements of array can sum up to (Sum of nums)/2
            => 0/1 Knapsack problem
        */ 
        const int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        
        //odd is impossible
        if (sum % 2 == 1) {
            return false;
        }
        
        vector<vector<bool>> dp(n, vector<bool>(sum, false));
        //dp[i][j] := whether there exists sum of elements is j, when considering nums[0:i]
        
        //B.C
        dp[0][nums[0]] = true;
        
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= sum/2; ++j) {
                if (nums[i] == j) {
                    dp[i][j] = true;
                }
                else if (nums[i] < j) {
                    //pick or not pick
                    dp[i][j] = (dp[i-1][j] || dp[i-1][j-nums[i]]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n-1][sum/2];
    }
};