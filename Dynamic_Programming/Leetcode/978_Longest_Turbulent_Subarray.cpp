//2021/8/3
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 1, n = arr.size();
        vector<int> dp1(n, 0), dp2(n, 0);
        //dp1[i] := maximum turbulent subarry end with arr[i], which arr[i] > arr[i-1]
        //dp2[i] := maximum turbulent subarry end with arr[i], which arr[i] < arr[i-1]

        //B.C.
        dp1[0] = dp2[0] = 1;

        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i-1]) {
                dp1[i] = dp2[i-1] + 1;
                dp2[i] = 1;
            }
            else if (arr[i] < arr[i-1]) {
                dp2[i] = dp1[i-1] + 1;
                dp1[i] = 1;
            }
            else {
                dp1[i] = dp2[i] = 1;
            }
            ans = max({ans, dp1[i], dp2[i]});
        }
        
        return ans;
    }
};