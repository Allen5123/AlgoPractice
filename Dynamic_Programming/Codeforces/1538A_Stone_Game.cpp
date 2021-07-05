//2021/7/4
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t > 0) {
        int n, leastPow = INT_MAX, greatestPow = INT_MIN;
        cin >> n;
        vector<int> pow(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> pow[i];
            leastPow = min(pow[i], leastPow);
            greatestPow = max(pow[i], greatestPow);
        }
        vector<vector<int>> dp(n, vector<int>(n, 0)); //dp[i][j] := minimum move of pow[i:j]

        //B.C.
        for (int i = 0; i < n; ++i) {
            dp[i][i] = (pow[i] == leastPow || pow[i] == greatestPow)? 1 : 0;
        }

        for (int k = 2; k <= n; ++k) {
            for (int i = 0; i + k - 1 < n; ++i) {
                int j = i + k - 1;
                if (dp[i+1][j] == 0 && dp[i][j-1] == 0) { // interval don't contain leastPow & greatestPow
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]); //take left or right
                }
            }
        }
        cout << dp[0][n-1] << "\n";
        --t;
    }
}