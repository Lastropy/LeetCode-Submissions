class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& g, int idx, int col, int n){
        if(col < 0 || idx >= n || col >= n) return 1e9;
        if(idx == n-1) return g[idx][col];
        if(dp[idx][col] != -1e6) return dp[idx][col];
        int minFall = 1e9;
        for(int i = 0; i < n; i++){
            if(i == col) continue;
            minFall = min(minFall, solve(g, idx + 1, i, n));
        }
        return dp[idx][col] = g[idx][col] + minFall;
    }
    
    int minFallingPathSum(vector<vector<int>>& g) {
        int ans = 1e9, n = g.size();
        dp.resize(n, vector<int>(n, -1e6));
        for(int i = 0; i < n; i++){
            ans = min(ans, solve(g, 0, i, n));
        }
        return ans;
    }
};