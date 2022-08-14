class Solution {
public:
    int f(vector<int> &p, int idx, bool buy, int fee, vector<vector<int>> &dp){
        int n = p.size();
        if(idx == n) return 0;
        
        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        int ans = 0;
        if(buy){
            int b = -p[idx] + f(p, idx+1, 0, fee, dp);
            int nb = 0 + f(p, idx+1, 1, fee, dp);
            ans = max(b, nb);
        }
        else{
            int s = p[idx] - fee + f(p, idx+1, 1,fee, dp);
            int ns = 0 + f(p, idx+1, 0,fee, dp);
            ans = max(s, ns);
        }
        return dp[idx][buy] = ans;
        
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return f(prices, 0, 1, fee, dp);
    }
};