class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, int tar_row, int tar_col, vector<vector<int>>& g){
        if(i > tar_row || j > tar_col) return 1e9;
        if(i == tar_row && j == tar_col) return g[tar_row][tar_col];
        if(dp[i][j] != -1) return dp[i][j];
        int right = solve(i + 1, j, tar_row, tar_col, g);        
        int down = solve(i, j + 1, tar_row, tar_col, g);
        return dp[i][j] = g[i][j] + min(right, down);
    }
    
    int minPathSum(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        dp.resize(m, vector<int>(n, -1));
        return solve(0, 0, m - 1, n - 1, g);
    }
};