//2021/7/6
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dp1(nums.size(), 0); //maximum positive product end with nums[i]
        vector<int> dp2(nums.size(), 0); //minimum negative product end with nums[i]
        int ans = 0;
        ans = nums[0];
        dp1[0] = (nums[0] >= 0)? nums[0] : 0;
        dp2[0] = (nums[0] < 0)? nums[0] : 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                dp1[i] = max(nums[i], dp1[i-1]*nums[i]);
                dp2[i] = min(nums[i], dp2[i-1]*nums[i]);
            }
            else {
                dp1[i] = max(nums[i], dp2[i-1]*nums[i]);
                dp2[i] = min(nums[i], dp1[i-1]*nums[i]);
            }
            ans = max(ans, dp1[i]);
        }
        return ans;
    }
};