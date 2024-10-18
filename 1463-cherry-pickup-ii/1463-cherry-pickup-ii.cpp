class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<vector<int>>& g, int p, int x,int y){
        if(p == g.size() || x < 0 || y < 0 || x == g[0].size() || y == g[0].size()) return -1e9;
        if(p == g.size() - 1) return g[p][x] + g[p][y];
        if(dp[p][x][y] != -1e9) return dp[p][x][y];
        int ans = -1e9;
        if(x - 1 != y - 1) ans = max(ans, solve(g, p + 1, x - 1, y - 1));
        if(x - 1 != y + 1) ans = max(ans, solve(g, p + 1, x - 1, y + 1));
        if(x - 1 != y) ans = max(ans, solve(g, p + 1, x - 1, y));
        
        if(x != y - 1) ans = max(ans, solve(g, p + 1, x, y - 1));
        if(x != y + 1) ans = max(ans, solve(g, p + 1, x, y + 1));
        if(x != y) ans = max(ans, solve(g, p + 1, x, y));
        
        if(x + 1 != y - 1) ans = max(ans, solve(g, p + 1, x + 1, y - 1));
        if(x + 1 != y + 1) ans = max(ans, solve(g, p + 1, x + 1, y + 1));        
        if(x + 1 != y) ans = max(ans, solve(g, p + 1, x + 1, y));
        
        return  dp[p][x][y] = g[p][x] + g[p][y] + ans;
    }
    
    int cherryPickup(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        dp.resize(m, vector<vector<int>>(n, vector<int>(n, -1e9)));
        return solve(g, 0, 0, n-1);
    }
};