//2021/8/18
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size(), ans = INT_MIN;
        vector<int> dp1(n, INT_MIN), dp2(n, INT_MIN);
        //dp1[i] := maximum subarray sum end with arr[i]
        //dp2[i] := maximum subarray sum start with arr[i]
        for (int i = 0; i < n; ++i) {
            dp1[i] = i > 0 ? max(dp1[i-1] + arr[i], arr[i]) : arr[i];
            dp2[n-1-i] = i > 0 ? max(dp2[n-i] + arr[n-1-i], arr[n-1-i]) : arr[n-1-i];
            ans = max({ans, dp1[i], dp2[i]}); // without deletion
        }
        for (int i = 1; i < n - 1; ++i) { // delete arr[i]
            ans = max(ans, dp1[i-1] + dp2[i+1]);
        }
        return ans;
    }
};