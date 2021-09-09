//2021/9/7
class Solution {
public:
    int deleteAndEarn(vector<int>& A) {
        sort(A.begin(), A.end());
        unordered_map<int, int> nums;
        vector<int> numList;
        for (const auto &num : A) {
            if (nums.count(num) > 0) {
                ++nums[num];
            }
            else {
                numList.push_back(num);
                nums[num] = 1;
            }
        }
        int n = numList.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            if (i == 1 || numList[i-1] - numList[i-2] != 1) {
                dp[i] = numList[i-1] * nums[numList[i-1]] + dp[i-1];
            }
            else {
                dp[i] = max(numList[i-1] * nums[numList[i-1]] + dp[i-2], dp[i-1]);
            }
        }
        return dp[n];
    }
};