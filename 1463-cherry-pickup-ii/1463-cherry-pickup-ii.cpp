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
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[m-1][i][j] = g[m-1][i];
                if(i == j) continue;
                dp[m-1][i][j] += g[m-1][j];
            }
        }
        
        for(int p = m - 2; p >= 0; p--){
            for(int x = 0; x < n; x++){
                for(int y = 0; y < n; y++){
                     int maxi = INT_MIN;
                    // Inner nested loops to try out 9 options (diagonal moves)
                    for (int dx = -1; dx <= 1; dx++) {
                        for (int dy = -1; dy <= 1; dy++) {
                            int ans = g[p][x];
                            if (x != y) ans += g[p][y];
                            if ((x + dx < 0 || x + dx >= n) || (y + dy < 0 || y + dy >= n))
                                ans = -1e9;
                            else
                                ans += dp[p + 1][x + dx][y + dy];
                            maxi = max(ans, maxi);
                        }
                    }
                    dp[p][x][y] = maxi; 
                }
            }
        }
        return dp[0][0][n-1];
    }
};