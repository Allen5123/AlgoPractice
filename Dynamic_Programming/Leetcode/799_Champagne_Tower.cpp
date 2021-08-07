//2021/7/29
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp1(query_row + 1, vector<double>(query_row + 1, 0)); //accumulate liquid
        vector<vector<double>> dp2(query_row + 1, vector<double>(query_row + 1, 0)); //excess liquid
        
        dp1[0][0] = (poured > 0)? 1. : 0;
        dp2[0][0] = (double)poured - dp1[0][0];
        
        for (int j = 1; j <= query_row; ++j) {
            for (int k = 0; k <= j; ++k) {
                dp1[j][k] += ((k < j)? dp2[j-1][k]/2 : 0.);
                dp1[j][k] += ((k > 0)? dp2[j-1][k-1]/2 : 0.);
                if (dp1[j][k] > 1.) {
                    dp2[j][k] = dp1[j][k] - 1.;
                    dp1[j][k] = 1.;
                }
            }
        }
        
        return dp1[query_row][query_glass];
    }
};