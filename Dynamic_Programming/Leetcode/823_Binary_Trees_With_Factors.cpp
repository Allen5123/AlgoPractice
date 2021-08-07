//2021/7/31
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        long ans = 0;
        unordered_map<long, long> dp; //dp[i] := # ways to build a binary tree with factors, which root value = i
        
        //B.C.
        dp.insert(make_pair(arr[0], 1));
        ans+=1;
        
        for (int i = 1; i < n; ++i) {
            long ways = 1; //leaf
            for (int j = 0; j < i; ++j) { //non-leaf
                if (arr[i]%arr[j] == 0) {
                    auto subtree1 = dp.find(arr[j]), subtree2 = dp.find(arr[i]/arr[j]);
                    if (subtree1 != dp.end() && subtree2 != dp.end())
                        ways = (ways + ((subtree1->second) * (subtree2->second)) % MOD) % MOD;
                }
            }
            ans = (ans + ways) % MOD;
            dp.insert(make_pair(arr[i], ways % MOD));
        }
        return ans;
    }
private:
    static constexpr long MOD = 1.e9 + 7;
};