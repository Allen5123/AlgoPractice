//2021/7/14
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), arrSum = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MIN;
        vector<int> dp(n, 0); //dp[i] := value of F(i)
        /*
            if we rotate i :
                1. k = nums[n-i]'s contribution would become 0 for F(i). Because it contributes k * (n-1) in F(i-1), this value should be substracted when calculating F(i) via F(i-1)
                2. all the other elements will contribute one times more than they are in F(i-1), so the additional contribution of these elements = arrSum - nums[n-i]
            
            => dp[i] = dp[i-1] - nums[n-i]*(n-1) + (arrSum - nums[n-i])
            => dp[i] = dp[i-1] + arrSum - num[n-i]*n
        */
        
        //B.C.
        for (int i = 1; i < n; ++i) {
            dp[0]+=nums[i]*i;
        }
        ans = dp[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i-1] + arrSum - nums[n-i] * n;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};