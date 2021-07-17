//2021/7/16
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int n = nums.size(), MAXDIFF = 4000;
        int ans = 0;
        map<pair<int, int>, int> dp;
        //dp[i][j] := # subarrays(length >= 2) ended with nums[i], which diffence is j
        if (n < 3) {
            return 0;
        }
        for (int i = 1; i < n; ++i) {
            int diff = nums[i] - nums[i-1];
            auto it = dp.find(pair<int, int>(i-1, diff));
            if (it != dp.end()) {
                ans+=(it->second);
                dp.insert(make_pair(make_pair(i, diff), it->second + 1));
            }
            dp.insert(make_pair(make_pair(i, diff), 1));
        }
        return ans;
    }
};