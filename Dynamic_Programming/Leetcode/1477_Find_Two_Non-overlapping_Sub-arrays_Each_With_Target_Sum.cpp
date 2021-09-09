//2021/8/25
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size(), ans = INT_MAX;
        unordered_map<int, int> prefix; //(key, val) = (prefixSum, i'th element)
        vector<int> dp(n + 1, INT_MAX); //dp[i] := minimum length of sub-array with target sum, considering first i'th elements
        
        prefix[0] = 0;
        for (int i = 1, sum = 0; i <= n; ++i) {
            sum+=arr[i-1];
            dp[i] = dp[i-1];
            if (prefix.find(sum-target) != prefix.end()) { //find target sum
                int start = prefix[sum-target] + 1, len = i - start + 1;
                dp[i] = min(dp[i], len);
                if (start > 0 && dp[start-1] < INT_MAX) {
                    ans = min(ans, len + dp[start-1]);
                }
            }
            prefix[sum] = i;
        }
        
        return ans < INT_MAX ? ans : -1;
    }
};