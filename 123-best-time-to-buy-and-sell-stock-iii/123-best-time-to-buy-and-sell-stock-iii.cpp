class Solution {
public:
    int f(vector<int> &p, int idx, bool buy, int lim, vector<vector<vector<int>>> &dp){
        int n = p.size();
        if(lim == 0 || idx == n) return 0; 
        if(dp[idx][buy][lim] != -1) return dp[idx][buy][lim];
        int ans = 0;
        if(buy){
            int b = -p[idx] + f(p, idx + 1, 0, lim, dp);
            int nb = 0 + f(p, idx + 1, 1, lim, dp);
            ans = max(b, nb);
        }
        else{
            int s = p[idx] + f(p, idx+1, 1, lim-1, dp);
            int ns = 0 + f(p, idx+1, 0, lim, dp);
            ans = max(s, ns);
        }
        return dp[idx][buy][lim] = ans;
    }
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(p, 0, 1, 2, dp);
    }
};