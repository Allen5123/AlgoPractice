//2021/7/12
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); //sort in ascending order
        vector<int> ans;
        vector<vector<int>> dp(n, vector<int>()); //dp[i] := Largest Divisible Subset end with nums[i](already sorted)
        
        //B.C
        dp[0].push_back(nums[0]);
        ans = dp[0];
        
        for (int i = 1; i < n; ++i) {
            //default
            dp[i].push_back(nums[i]);
            for (int j = i - 1; j >= 0; --j) {
                //iterate all divisor of nums[i] between nums[i:i-1]
                if (nums[i] % nums[j] == 0) {
                    if (dp[i].size() < dp[j].size() + 1) {
                        dp[i] = dp[j];
                        dp[i].push_back(nums[i]);
                        if (ans.size() < dp[i].size()) {
                            ans = dp[i];
                        }   
                    }
                }
            }
        }
        return ans;
    }
};