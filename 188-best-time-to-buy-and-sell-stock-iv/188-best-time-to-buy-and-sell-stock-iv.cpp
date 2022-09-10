class Solution {
public:
    int f(vector<int> &p, int idx, int k, bool buy, vector<vector<vector<int>>> &dp){
        int n = p.size();
        if(idx == n || k == 0) return 0;
        if(dp[idx][k][buy] != -1) return dp[idx][k][buy];
        
        int ans = 0;
        
        if(buy){
            int b = -p[idx] + f(p, idx + 1, k, 0, dp);
            int nb = 0 + f(p, idx + 1, k , 1, dp);
            ans = max(b, nb);
        }
        else{
            int s = p[idx] + f(p, idx + 1, k - 1, 1, dp);
            int ns = 0 + f(p, idx+1, k, 0, dp);
            ans = max(s, ns);
        }
        
        return dp[idx][k][buy] = ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, - 1)));
        return f(prices, 0, k, 1, dp);
    }
};