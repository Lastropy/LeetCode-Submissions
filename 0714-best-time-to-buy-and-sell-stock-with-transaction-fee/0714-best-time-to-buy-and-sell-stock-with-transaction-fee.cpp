class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int> &p, int idx, bool bought, int fee) {
        if(idx >= p.size()) return 0;
        if(dp[idx][bought] != -1e9) return dp[idx][bought];
        if(!bought) {
            int buy = -p[idx] + solve(p, idx + 1, !bought, fee);
            int notBuy = 0 + solve(p, idx + 1, bought, fee);
            return dp[idx][bought] = max(buy, notBuy);
        } else {
            int sell = +p[idx] - fee + solve(p, idx + 1, !bought, fee);
            int notSell = 0 + solve(p, idx + 1, bought, fee);
            return dp[idx][bought] = max(sell, notSell);
        }
    }
    
    int maxProfit(vector<int>& p, int fee) {
        dp.resize(p.size(), vector<int>(2, -1e9));
        return solve(p, 0, false, fee);
    }
};