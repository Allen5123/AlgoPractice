//2021/7/8
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        istringstream iss(expression);
        vector<int> dp[21][21];
        //dp[i][j] := all possible result when considering the interval from "operand" i to j
        vector<pair<int, string>> operand; //record all operand (index, operandStr)
        int pos = 0;
        while (true) {
            int num = 0;
            char op = '\0';
            if (iss >> num) {
                string opstr = to_string(num);
                operand.push_back(make_pair(pos, opstr));
                pos+=(opstr.length());
            }
            else { break; }
            if (iss >> op) { ++pos; }
            else { break; }
        }
        
        int n = operand.size();
        for (int l = 1; l <= n; ++l) {
            for (int i = 0; i + l - 1 < n; ++i) {
                int j = i + l - 1;
                if (l == 1) {
                    dp[i][j].push_back(stoi(operand[i].second));
                }
                else {
                    for (int m = 0; m < l; ++m) {
                        for (auto p : dp[i][i+m]) {
                            for (auto q : dp[i+m+1][j]) {
                                char operator_ = expression[operand[i+m].first + operand[i+m].second.length()];
                                dp[i][j].push_back(Calculate(p, q, operator_));
                            }
                        }
                    }
                }
            }
        }
        return dp[0][n-1];
    }
private:
    int Calculate(int op1, int op2, char operator_) const {
        int res = 0;
        switch (operator_) {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
        }
        return res;
    }
};