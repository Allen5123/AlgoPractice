//2021/6/30
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0); //dp[i] := the maximum index that first i elements can jump
        dp[0] = nums[0];
        if (nums.size() == 1) {
            return true;
        }
        for (int i = 1; i < nums.size(); ++i) {
            if (dp[i-1] >= i) {
                dp[i] = max(dp[i-1], nums[i] + i);
                if (dp[i] >= nums.size() - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};