//2021/7/18
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto Cmp = [] (vector<int>& a, vector<int>& b) {return (a[1] < b[1]);};
        sort(intervals.begin(), intervals.end(), Cmp); //sorted by end time
        
        int n = intervals.size();
        vector<int> dp(n + 1, INT_MAX); //dp[i] := minimum number to remove when considering first i'th intervals
        
        //B.C.
        dp[0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            int overlap = -1;
            //find all overlapping intervals
            for (int j = i - 1; j >= 1; --j) {
                if (intervals[i-1][0] < intervals[j-1][1]) {
                    overlap = j;
                }
                else {
                    break;
                }
            }
            if (overlap >= 1) {
                //remove i'th interval or all the interval overlap with it
                dp[i] = min(1 + dp[i-1], i - overlap + dp[overlap-1]);
            }
            else {
                dp[i] = dp[i-1];
            }
        }
        return dp[n];
    }
};