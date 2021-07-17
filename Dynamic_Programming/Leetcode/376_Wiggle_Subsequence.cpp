//2021/7/13
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, 0); //dp1[i] := longest wiggle seq which last difference is "positive" between nums[0:i]
        vector<int> dp2(n, 0); //dp2[i] := longest wiggle seq which last difference is negative between nums[0:i]
        dp1[0] = dp2[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i-1] > 0) {
                dp1[i] = dp2[i-1] + 1;
                dp2[i] = dp2[i-1];
            }
            else if (nums[i] - nums[i-1] < 0) {
                dp1[i] = dp1[i-1];
                dp2[i] = dp1[i-1] + 1;
            }
            else {
                dp1[i] = dp1[i-1];
                dp2[i] = dp2[i-1];
            }
        }
        return max(dp1[n-1], dp2[n-1]);
    }
};