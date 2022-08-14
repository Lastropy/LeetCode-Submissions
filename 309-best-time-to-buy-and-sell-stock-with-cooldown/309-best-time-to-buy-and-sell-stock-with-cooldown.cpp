class Solution {
public:
    int f(vector<int> &p, int idx, bool buy, bool cool_down, vector<vector<vector<int>>> &dp){
        int n = p.size();
        if(idx >= n) return 0; 

        if(dp[idx][buy][cool_down] != -1) return dp[idx][buy][cool_down];
        int ans = 0;
        
        if(buy){
            int b = -p[idx] + f(p, idx + 1, 0, 0, dp); 
            int nb = 0 + f(p, idx + 1, 1, 0, dp);

            if(cool_down) ans = nb;
            else ans = max(b, nb);
        }
        else{
            int s = p[idx] + f(p, idx+1, 1, 1, dp);
            int ns = 0 + f(p, idx+1, 0, 0, dp);
            ans = max(s, ns);
        }
        return dp[idx][buy][cool_down] = ans;
    }
    int maxProfit(vector<int>& p) {
        bool cool_down = 0;
        int n = p.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
        return f(p, 0, 1, 0, dp);
    }
};