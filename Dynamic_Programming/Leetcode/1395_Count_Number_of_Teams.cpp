//2021/6/28
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int dp[1000][2], ans = 0;
        //dp[i][0] := # length 2 decreasing order that end with i elements
        //dp[i][1] := # length 2 increasing order that end with i elements
        fill_n(&dp[0][0], sizeof(dp)/sizeof(int), 0);
        dp[1][0] = (rating[1] < rating[0])? 1 : 0;
        dp[1][1] = (rating[1] > rating[0])? 1 : 0;
        for (int i = 2; i < rating.size(); ++i) {
            int low = 0, high = 0;
            for (int j = 0; j < i; ++j) {
                if (rating[i] < rating[j]) {
                    ++low;
                    ans+=dp[j][0];
                } 
                else if (rating[i] > rating[j]) {
                    ++high;
                    ans+=dp[j][1];
                }
                else {}   
            }
            dp[i][0] = low;
            dp[i][1] = high;
        }
        return ans;
    }
};