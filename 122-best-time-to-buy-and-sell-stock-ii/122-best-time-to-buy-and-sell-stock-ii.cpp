class Solution {
public:
    int f(vector<int> &p, int idx, bool buy, vector<vector<int>> &dp){
        int n = p.size();
        if(idx == n) return 0;
        
        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        int ans = 0;
        if(buy){
            int b = -p[idx] + f(p, idx+1, 0, dp);
            int nb = 0 + f(p, idx+1, 1, dp);
            ans = max(b, nb);
        }
        else{
            int s = p[idx] + f(p, idx+1, 1, dp);
            int ns = 0 + f(p, idx+1, 0, dp);
            ans = max(s, ns);
        }
        return dp[idx][buy] = ans;
        
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return f(prices, 0, 1,dp);
    }
};