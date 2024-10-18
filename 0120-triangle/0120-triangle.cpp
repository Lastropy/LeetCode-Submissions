class Solution {
public:
    unordered_map<string, int> dp;
    int solve(vector<vector<int>>& g, int idx, int col, int n){
        if(col > idx || idx >= n) return 1e9;
        if(idx == n-1) return g[idx][col];
        string key = to_string(idx) + "|" + to_string(col);
        if(dp.count(key)) return dp[key];
        int bottom = solve(g, idx + 1, col, n);
        int right = solve(g, idx + 1, col + 1, n);
        return dp[key] = g[idx][col] + min(bottom, right);
    }
    
    int minimumTotal(vector<vector<int>>& g) {
        int n = g.size();
        return solve(g, 0, 0, n);
    }
};