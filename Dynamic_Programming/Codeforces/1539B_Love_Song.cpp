//2021/7/4
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n = 0, p = 0;
    string s;
    cin >> n >> p >> s;
    vector<int> dp(n + 1, 0); //ans of s[1:i] (p.s. assume index start from 1)
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i-1] + (s[i-1] - 'a' + 1); //prefix + expand char
    }
    for (int i = 0; i < p; ++i) {
        int l = 0, r = 0;
        cin >> l >> r;
        cout << dp[r] - dp[l-1] << "\n";
    }
    return 0;
}