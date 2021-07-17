#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
int main()
{
    string s;
    int n, k;
    uint64_t ans = 0;
    cin >> n >> k >> s;
    vector<int> dp(n + 1, 0); //dp[i] := # of substr end with s[i], index start from 1
    bool letters[26] = {false};
    for (int i = 0; i < k; ++i) {
        char c;
        cin >> c;
        letters[c-'a'] = true;
    }
    for (int i = 1; i <= n; ++i) {
        if (letters[s[i-1]-'a']) {
            dp[i] = dp[i-1] + 1;
            ans+=dp[i];
        }
    }
    cout << ans << "\n";
    return 0;
}