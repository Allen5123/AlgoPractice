//2021/7/9
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> sell(n, 0); //sell[i] := maximum profit end with sell, when considering first i'th days
        vector<int> buy(n, 0); //buy[i] := maximum profit end with buy, when considering first i'th days
        vector<int> cooldown(n, 0); //cooldown[i] := maximum profit end with cooldown, when considering first i'th days
        sell[0] = cooldown[0] = 0;
        buy[0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            sell[i] = max(buy[i-1] + prices[i], sell[i-1]);
            buy[i] = max(cooldown[i-1] - prices[i], buy[i-1]);
            cooldown[i] = max({sell[i-1], buy[i-1], cooldown[i-1]});
        }
        return max({sell[n-1], buy[n-1], cooldown[n-1]});
    }
};