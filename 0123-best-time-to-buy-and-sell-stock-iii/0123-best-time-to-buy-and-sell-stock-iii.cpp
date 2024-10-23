class Solution {
public:
    int f(vector<int> &p, int idx, bool buy, int lim, vector<vector<vector<int>>> &dp){
        if(lim == 0 || idx == p.size()) return 0; 
        if(dp[idx][buy][lim] != -1) return dp[idx][buy][lim];
        if(buy){
            int b = -p[idx] + f(p, idx + 1, 0, lim, dp);
            int nb = 0 + f(p, idx + 1, 1, lim, dp);
            return dp[idx][buy][lim] = max(b, nb);
        }
        else{
            int s = p[idx] + f(p, idx+1, 1, lim-1, dp);
            int ns = 0 + f(p, idx+1, 0, lim, dp);
            return dp[idx][buy][lim] = max(s, ns);
        }
    }
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(p, 0, 1, 2, dp);
    }
};