//2021/7/23
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        dp.insert(make_pair(vector<int>(needs.size(), 0), 0)); //Base case
        return Calculate(needs, price, special);
    }
private:
    map<vector<int>, int> dp; //dp[i][j] := lowest price at state i
    int Calculate (const vector<int>& needs, const vector<int>& price, const vector<vector<int>>& special) {
        auto it = dp.find(needs);
        if (it != dp.end()) {
            return it->second;
        }
        
        int lowest = 0;     
        //Don't use special
        for (int i = 0; i < needs.size(); ++i) {
            lowest+=(needs[i]*price[i]);
        }
        //try to use special
        for (const auto &spec : special) {
            int cost = 0;
            if (CanUse(needs, spec)) {
                vector<int> temp = AfterUsed(needs, spec);
                lowest = min(lowest, spec[spec.size() - 1] + Calculate(temp, price, special));
            }
        }
        dp.insert(make_pair(needs, lowest));
        return lowest;
    }
    bool CanUse (const vector<int>& needs, const vector<int>& spec) const {
        for (int i = 0; i < needs.size(); ++i) {
            if (needs[i] < spec[i]) {
                return false;
            }
        }
        return true;
    }
    vector<int> AfterUsed (const vector<int>& needs, const vector<int>& spec) const {
        vector<int> res(needs.size(), 0);
        for (int i = 0; i < needs.size(); ++i) {
            res[i] = needs[i] - spec[i];
        }
        return res;
    }
};