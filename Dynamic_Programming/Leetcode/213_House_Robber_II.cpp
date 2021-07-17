//2021/7/7
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n + 1, 0); //dp1[i] := maximum money, when considering first i'th houses and "rob" 1st house 
        vector<int> dp2(n + 1, 0); //dp2[i] := maximum money, when considering first i'th houses and "don't rob" 1st house
        dp1[1] = nums[0];
        dp2[1] = 0;
        for (int i = 2; i <= n; ++i) {
            if (i < n) {
                dp1[i] = max(dp1[i-1], nums[i-1] + dp1[i-2]);
            }
            else {
                dp1[i] = dp1[i-1];
            }
            dp2[i] = max(dp2[i-1], nums[i-1] + dp2[i-2]);
        }
        return max(dp1[n], dp2[n]);
    }
};