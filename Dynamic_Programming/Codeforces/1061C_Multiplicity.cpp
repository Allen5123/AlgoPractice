//2021/7/5
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    /* original approach
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[i][j] := # of length j good sequences which only consider first i'th array elements, i,j>=1
    dp[i][j] = dp[i-1][j] + dp[i-1][j-1], if i|a[i-1]
               dp[i-1][j], otherwise
    Exceed memory limit => need to compression
    */
    static constexpr int modulo = 1e9 + 7;
    int n, ans = 0;
    cin >> n;
    vector<int> arr(n, 0);
    vector <int> dp(n + 1, 0); // compression 2D->1D
    auto Divisor = [n](int x) {
        vector<int> div;
        for (int i = 1; i * i <= x && i <= n; ++i) {
            if (x % i == 0) {
                div.push_back(i);
                if (x/i != i && x/i <= n) {
                    div.push_back(x/i);
                }
            }
        }
        sort(div.begin(), div.end(), greater<int>());
        return div;
    };
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    /*original approach
    B.C.
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (arr[i-1] % j == 0) {
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % modulo;
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        ans = (ans + dp[n][i]) % modulo;
    }
    */

    //compression
    //B.C.
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        //find divisor of arr[i-1];
        vector<int> div = Divisor(arr[i-1]);
        for (int k = 0; k < div.size(); ++k) {
            int j = div[k];
            dp[j] = (dp[j] + dp[j-1]) % modulo;
        }
    }
    for (int i = 1; i <= n; ++i) {
        ans = (ans + dp[i]) % modulo;
    }
    cout << ans << "\n";
    return 0;
}