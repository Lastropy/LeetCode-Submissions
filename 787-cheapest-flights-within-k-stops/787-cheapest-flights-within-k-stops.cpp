class Solution {
public:
    int f(vector<vector<pair<int, int>>> &g, int s, int d, int k, vector<vector<int>> &dp)
    {
        if(s == d) return 0;
        if(k < 0) return INT_MAX;
        if(dp[s][k] != -1) return dp[s][k];
        
        int ans = INT_MAX;
        int cst;
        for(auto [node, c]: g[s]){
            cst = f(g, node, d, k - 1, dp);
            if(cst != INT_MAX)
                ans = min(ans, c + cst);
        }
        return dp[s][k] = ans;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<vector<pair<int, int>>> g(n);
        for(auto f: flights)
            g[f[0]].push_back({f[1], f[2]});
        
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        int ans = f(g, src, dst, k, dp);
        return ans == INT_MAX ? -1: ans;
    }
};