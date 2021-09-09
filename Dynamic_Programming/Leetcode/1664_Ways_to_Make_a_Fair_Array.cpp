//2021/9/2
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<vector<int>> start(n, vector<int>(2, 0)), end(n, vector<int>(2, 0));
        //start[i][0] := sum of the even-indexed values with index i
        //start[i][1] := sum of the odd-indexed values start with index i
        //end[i][0] := sum of the even-indexed values  end with index i
        //end[i][1] := sum of the odd-indexed values  end with index i
        
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                end[i][0] = (i >= 1 ? end[i-1][0] : 0) + nums[i];
                end[i][1] = (i >= 1 ? end[i-1][1] : 0);
            }
            else {
                end[i][0] = (i >= 1 ? end[i-1][0] : 0);
                end[i][1] = (i >= 1 ? end[i-1][1] : 0) + nums[i];
            }
        }
        
        for (int i = n - 1; i >= 0; --i) {
            if (i % 2 == 0) {
                start[i][0] = (i + 1 < n ? start[i+1][0] : 0) + nums[i];
                start[i][1] = (i + 1 < n ? start[i+1][1] : 0);
            }
            else {
                start[i][0] = (i + 1 < n ? start[i+1][0] : 0);
                start[i][1] = (i + 1 < n ? start[i+1][1] : 0) + nums[i];
            }
        }

        for (int i = 0; i < n; ++i) {
            int oddsum = (i > 0 ? end[i-1][1] : 0) + (i + 1 < n ? start[i+1][0] : 0);
            int evensum = (i > 0 ? end[i-1][0] : 0) + (i + 1 < n ? start[i+1][1] : 0);
            if (oddsum == evensum) {
                ++ans;
            }
        }
        return ans;
    }
};